/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_env_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:04:52 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/29 19:56:31 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pars.h"

static int	special_pars_env(t_token **token, int type)
{
	if ((*token)->val != 0)
		free((*token)->val);
	if (type == 0)
	{
		(*token)->val = ft_strdup("minishell");
		if ((*token)->val == 0)
			return (1);
	}
	else
	{
		(*token)->val = ft_itoa(g_exit_status);
		if ((*token)->val == 0)
			return (1);
	}
	return (0);
}

static int	pars_env(t_token **now, t_env **env_list)
{
	(*now)->type = 'w';
	if (ft_strncmp((*now)->val, "$0", 3) == 0)
		return (special_pars_env(now, 0));
	else if (ft_strncmp((*now)->val, "$?", 3) == 0)
		return (special_pars_env(now, 1));
	else
		return (env_search(*now, *env_list));
}

int	rotate_env_token(t_token **token, t_env **env_list)
{
	t_token	*tmp;

	tmp = *token;
	while (tmp != 0)
	{
		if (tmp->type == 't' && ft_strncmp("<<", tmp->val, 3) == 0)
		{
			if (tmp->next != 0 && tmp->next->type == 'e')
				tmp->next->type = 'w';
		}
		else if (tmp->type == 'e')
		{
			if (pars_env(&tmp, env_list))
				return (1);
		}
		else if (tmp->val[0] == '\"')
		{
			if (env_search(tmp, *env_list))
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
