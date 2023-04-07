/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_env_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:04:52 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/07 16:01:00 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pars.h"

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
		else if (tmp->type == 'e' || tmp->val[0] == '\"')
		{
			if (env_search(tmp, *env_list))
				return (1);
			if (tmp->type == 'e')
				tmp->type = 'w';
		}
		tmp = tmp->next;
	}
	return (0);
}
