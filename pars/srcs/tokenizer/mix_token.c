/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:38:23 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/07 16:45:32 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pars.h"

static int	fusion_token(t_token **token)
{
	t_token	*now;
	char	*tmp_str;

	now = *token;
	tmp_str = ft_strjoin(now->val, now->next->val);
	if (!tmp_str)
		return (err_msg("Error : Malloc failed(fusion_token)", 1, 0));
	if (now->val != 0)
		free(now->val);
	now->val = tmp_str;
	lstdelone_token_elem(now, now->next);
	if (now->type == 't' && (ft_strncmp(now->val, "<<", 3) == 0
			|| ft_strncmp(now->val, ">>", 3) == 0))
		return (1);
	return (2);
}

static char	*ft_strchr_null(const char *str, int c)
{
	size_t			idx;
	unsigned char	tgt;

	idx = 0;
	tgt = (unsigned char)c;
	if (str == 0)
		return (0);
	while (str[idx])
	{
		if (str[idx] == tgt)
			return ((char *)str + idx);
		idx++;
	}
	return (0);
}

static int	select_phase(t_token **now, t_token **after, int flag)
{
	if ((*now)->type == 'w' && (*after)->type == 'w' && flag == 1)
		return (fusion_token(now));
	else if ((*now)->type == 'e' && (*after)->type != 't')
	{
		if ((*after)->val[0] && !ft_strchr_null("\'\"", (*after)->val[0]))
			return (fusion_token(now));
		else
			return (1);
	}
	else if ((*now)->type == 't' && (*after)->type == 't')
	{
		if ((!ft_strncmp((*now)->val, "<", 2)
				&& !ft_strncmp((*after)->val, "<", 2))
			|| (!ft_strncmp((*now)->val, ">", 2)
				&& !ft_strncmp((*after)->val, ">", 2)))
			return (fusion_token(now));
		else
			return (1);
	}
	return (1);
}

int	mix_token(t_token **token, int quote_flag)
{
	t_token	*now;
	int		select;

	now = *token;
	while (now->next != 0)
	{
		select = select_phase(&now, &(now->next), quote_flag);
		if (select == 0)
			return (1);
		else if (select == 1)
			now = now->next;
	}
	return (0);
}
