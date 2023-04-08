/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:51:38 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/07 21:54:34 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pars.h"

int	trim_token(t_token **token)
{
	t_token	*now;

	now = *token;
	if (now != 0 && now->type == 't' && (ft_strncmp(now->val, " ", 2) == 0
			|| now->val[0] == 0))
	{
		*token = (*token)->next;
		lstdelone_token(now);
		now = *token;
	}
	while (now != 0 && now->next != 0)
	{
		if (now != 0 && now->next != 0 && now->next->type == 't'
			&& (!now->next->val[0] || !ft_strncmp(now->next->val, " ", 2)))
			lstdelone_token_elem(now, now->next);
		if (now->next != 0 && ft_strncmp(now->next->val, " ", 2)
				&& now->next->val[0])
			now = now->next;
		else if (now->next != 0 && now->type != 't')
			now = now->next;
	}
	if (now != 0 && now->next == 0 && now->type == 't'
		&& (!ft_strncmp(now->val, " ", 2) || !now->val[0]))
		return (1);
	return (0);
}
