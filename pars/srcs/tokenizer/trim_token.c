/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:51:38 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/12 19:54:46 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pars.h"

static t_token	*continue_trim_token(t_token **token, int phase)
{
	t_token	*now;

	now = *token;
	if (phase == 0)
	{
		while (now != 0 && !now->val[0])
		{
			*token = (*token)->next;
			lstdelone_token(now);
			now = *token;
		}
	}
	else
	{
		while (now != 0 && !ft_strncmp(now->val, " ", 2))
		{
			*token = (*token)->next;
			lstdelone_token(now);
			now = *token;
		}
	}
	return (now);
}

static void	trim_blank_token(t_token **token)
{
	t_token	*now;

	now = *token;
	while (now != 0 && now->next != 0)
	{
		if (now->next != 0 && now->next->type == 't'
			&& !now->next->val[0])
			lstdelone_token_elem(now, now->next);
		if (now->next != 0 && now->next->type != 't' && now->next->next == 0
			&& !now->next->val[0])
			lstdelone_token_elem(now, now->next);
		if (now->next != 0 && (now->next->type != 't' || now->next->val[0]))
			now = now->next;
	}
}

int	trim_token(t_token **token, int phase)
{
	t_token	*now;

	now = *token;
	now = continue_trim_token(&now, phase);
	*token = now;
	if (phase == 0)
		trim_blank_token(&now);
	else
	{
		while (now != 0 && now->next != 0)
		{
			if (now->next != 0 && now->next->type == 't'
				&& !ft_strncmp(now->next->val, " ", 2))
				lstdelone_token_elem(now, now->next);
			if (now->next != 0 && now->next->type != 't' && now->next->next == 0
				&& !ft_strncmp(now->next->val, " ", 2))
				lstdelone_token_elem(now, now->next);
			if (now->next != 0 && (now->next->type != 't'
					|| ft_strncmp(now->next->val, " ", 2)))
				now = now->next;
		}
	}
	return (0);
}
