/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:51:38 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/28 20:10:58 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pars.h"

/*
	trim_token : 각 토큰에서 불필요한 공백을 제거하고 공백으로만 이루어진 토큰도 제거(인용 제외)
*/

int	trim_token(t_token **token)
{
	t_token	*now;

	now = *token;
	if (now->type == 't' && ft_strncmp(now->val, " ", 2) == 0)
	{
		*token = (*token)->next;
		lstdelone_token(now);
		now = *token;
	}
	while (now != 0 && now->next != 0)
	{
		if (now->next->type == 't' && ft_strncmp(now->next->val, " ", 2) == 0)
			lstdelone_token_elem(now, now->next);
		if (now != 0 && now->next != 0 && now->next->type != 't')
			now = now->next;
	}
	if (*token == 0)
		return (1);
	return (0);
}
