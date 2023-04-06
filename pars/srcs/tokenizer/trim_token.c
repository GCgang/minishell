/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:51:38 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/06 13:19:16 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pars.h"

//void	last_search(t_token **token)
//{
//	t_token	*now;
//	char	*str;

//	while (now != 0)
//	{
//		if (!ft_strncmp(now->val, "", 1))
//			now->type = 't';
//		str = ft_strdup(" ");
//		now = now->next;
//	}
//}

int	trim_token(t_token **token)
{
	t_token	*now;

	now = *token;
	//last_search(token);
	if (now->type == 't' && (ft_strncmp(now->val, " ", 2) == 0))
	{
		*token = (*token)->next;
		lstdelone_token(now);
		now = *token;
	}
	while (now != 0 && now->next != 0)
	{
		if (now->next->type == 't' && !ft_strncmp(now->next->val, " ", 2))
			lstdelone_token_elem(now, now->next);
		if (now->next != 0 && ft_strncmp(now->next->val, " ", 2))
			now = now->next;
	}
	if (now != 0 && now->type == 't' && !ft_strncmp(now->val, " ", 2))
		return (1);
	return (0);
}
