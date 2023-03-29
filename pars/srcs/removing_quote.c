/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removing_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:57 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/28 17:01:45 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pars.h"

/*
	pars_extra_token : 환경변수, 인용 해석, 메타문자 유형별 정리
	1. redirection 중, << 뒤에 오는 토큰은 heredoc으로 분류
	2. record_quote : 현재 토큰의 따옴표 위치를 분석
	3. env_search : 토큰에 존재하는 환경변수를 파싱, heredoc은 해당 토큰이 
	4. split_word_ifs : 단어 분할 기준, IFS가 있는 지 확인하고 IFS에 해당하는 내용물을 별도 토큰으로 분리
	5. remove_quote : 메타 문자가 아닌 단순 문자열인 경우, 인용 문구를 제거한다
*/

static void	chk_quote(t_token **token, char tgt, int *idx)
{
	t_token	*tmp;

	tmp = *token;
	tmp->quote[*idx] = '1';
	(*idx)++;
	while (tmp->val[*idx] != 0 && tmp->val[*idx] != tgt)
	{
		tmp->quote[*idx] = '0';
		(*idx)++;
	}
	tmp->quote[*idx] = '1';
}

static int	record_quote(t_token **token)
{
	int		idx;
	t_token	*tmp;

	idx = 0;
	tmp = *token;
	tmp->quote = (char *)malloc(sizeof(char)
			* (ft_strlen(tmp->val) + 1));
	if (tmp->quote == 0)
		return (1);
	while (tmp != 0 && tmp->val != 0 && tmp->val[idx] != 0)
	{
		tmp->quote[ft_strlen(tmp->val)] = 0;
		if (tmp->val[idx] == '\'')
			chk_quote(&tmp, '\'', &idx);
		else if (tmp->val[idx] == '\"')
			chk_quote(&tmp, '\"', &idx);
		else
			tmp->quote[idx] = '0';
		idx++;
	}
	return (0);
}

static int	remove_quote(t_token **token)
{
	int		idx;
	char	*tmp;

	idx = -1;
	while ((*token)->val != 0 && (*token)->val[++idx] != 0)
	{
		if (((*token)->val[idx] == '\'' || (*token)->val[idx] == '\"')
			&& (*token)->quote[idx] == '1')
		{
			(*token)->val[idx] = 0;
			tmp = ft_strjoin((*token)->val, (*token)->val + idx + 1);
			if (tmp == 0)
				return (1);
			free((*token)->val);
			(*token)->val = tmp;
			(*token)->quote[idx] = 0;
			tmp = ft_strjoin((*token)->quote, (*token)->quote + idx + 1);
			if (tmp == 0)
				return (1);
			free((*token)->quote);
			(*token)->quote = tmp;
			idx--;
		}
	}
	return (0);
}

int	removing_quote(t_token **token)
{
	t_token	*now;
	t_token	*before;

	now = *token;
	before = now;
	while (now != 0)
	{
		if (before != now && before->type == 'r'
			&& ft_strncmp(before->val, "<<", 3) == 0)
			now->type = 'h';
		if (record_quote(&now))
			return (1);
		before = now;
		now = now->next;
	}
	now = *token;
	while (now != 0)
	{
		if (now->type != 'r')
			if (remove_quote(&now))
				return (1);
		now = now->next;
	}
	return (0);
}
