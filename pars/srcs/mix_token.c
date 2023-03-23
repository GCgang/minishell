/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:38:23 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/22 16:46:52 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pars.h"

void	mix_token(t_token **token)
{
	t_token	*tmp;
	t_token	*next;
	char	*tmp_str;

	tmp = *token;
	while (tmp)
	{
		if (tmp->type == 'w' && tmp->next != 0)
		{
			if (tmp->next->type == 'w')
			{
				tmp_str = tmp->val;
				tmp->val = ft_strjoin(tmp->val, tmp->next->val);
				free(tmp_str);
				next = tmp->next->next;
				lstdelone_token(tmp->next, &free);
				tmp->next = next;
			}
		}
		tmp = tmp->next;
	}
}
