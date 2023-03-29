/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:38:23 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/28 13:56:06 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pars.h"

/*
	인용 부호를 제외하고 나머지 문자들을 조합한다.
	1. w + w => w
	2. e + w => if (e[1] != 0 && ft_strchr("0123456789", e[1]) != 0 && w[0] != 0 && ft_strchr("\"\'", w[0]) != 0) return (none fusion) else (fusion)
	3. t + t => if ((t0 == < && t1 == <) || (t0 == > && t1 == >)) return (fusion) else return (none fusion)
	4. e + e => (x)
		4-1. 4번은 1차 문자 집합이 된 이후에 rotate_token에서 융합
	5. 
*/

static int	fusion_token(t_token **token)
{
	t_token	*now;
	char	*tmp_str;

	now = *token;
	tmp_str = ft_strjoin(now->val, now->next->val);
	if (!tmp_str)
		return (err_msg("Error : Malloc failed(fusion_token)") - 1);
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
	else if ((*now)->type == 'e' && (*after)->type == 'w')
	{
		if (!ft_strchr_null("0123456789", (*now)->val[1]) && (*after)->val[0]
			&& (*after)->val[0] != '\'' && (*after)->val[0] != '\"')
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
