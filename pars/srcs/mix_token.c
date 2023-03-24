/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:38:23 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/23 19:55:40 by jaehjoo          ###   ########.fr       */
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

static void	fusion_token(t_token **token)
{
	t_token	*now;
	char	*tmp_str;

	now = *token;
	tmp_str = ft_strjoin(now->val, now->next->val);
	if (now->val != 0)
		free(now->val);
	now->val = tmp_str;
	lstdelone_token_elem(now, now->next, &free);
}

void	mix_token(t_token **token)
{
	t_token	*now;

	now = *token;
	while (now->next != 0)
	{
		if (now->type == 'w' && now->next->type == 'w')
			fusion_token(&now);
		else if (now->type == 'e' && now->next->type == 'w')
		{
			if (now->val[1] != 0 && ft_strchr("0123456789", now->val[1]) == 0
				&& now->next->val[0] != 0 && now->next->val[0] != '\'' && now->next->val[0] != '\"')
				fusion_token(&now);
			else
				now = now->next;
		}
		else if (now->type == 't' && now->next->type == 't')
		{
			if ((now->val[0] == '<' && now->next->val[0] == '<')
				|| (now->val[0] == '>' && now->next->val[0] == '>'))
				fusion_token(&now);
		}
		else
			now = now->next;
	}
}
