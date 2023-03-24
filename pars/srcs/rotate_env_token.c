/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_env_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:04:52 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/23 18:56:22 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pars.h"

static void	special_pars_env(t_token **token, t_env **env_list, int type)
{
	char	*tmp_str;

	tmp_str = (*token)->val;
	if (type == 0)
		(*token)->val = ft_strdup("minishell");
	else
		(*token)->val = ft_strdup((*env_list)->val);
	free(tmp_str);
}

void	rotate_env_token(t_token **token, t_env **env_list)
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
			if (ft_strncmp(tmp->val, "$0", 3) == 0)
				special_pars_env(&tmp, env_list, 0);
			else if (ft_strncmp(tmp->val, "$?", 3) == 0)
				special_pars_env(&tmp, env_list, 1);
			else
				env_search(tmp, *env_list);
			tmp->type = 'w';
		}
		tmp = tmp->next;
	}
	mix_token(token);
}
