/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_extra_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:57 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/24 16:04:03 by jaehjoo          ###   ########.fr       */
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
static void	chk_quote(t_token *token, char tgt, int *idx)
{
	token->quote[*idx] = '1';
	(*idx)++;
	while (token->val[*idx] != 0 && token->val[*idx] != tgt)
	{
		token->quote[*idx] = '0';
		(*idx)++;
	}
	token->quote[*idx] = '1';
}

static void	record_quote(t_token *token)
{
	int	idx;

	idx = 0;
	while (token != 0 && token->val != 0 && token->val[idx] != 0)
	{
		token->quote = (char *)malloc(sizeof(char) * (ft_strlen(token->val) + 1));
		token->quote[ft_strlen(token->val)] = 0;
		if (token->val[idx] == '\'')
			chk_quote(token, '\'', &idx);
		else if (token->val[idx] == '\"')
			chk_quote(token, '\"', &idx);
		else
			token->quote[idx] = '0';
		idx++;
	}
}

static void	remove_quote(t_token *token)
{
	int		idx;
	char	*tmp_val;
	char	*tmp_quote;

	idx = 0;
	while (token->val != 0 && token->val[idx] != 0)
	{
		if ((token->val[idx] == '\'' || token->val[idx] == '\"')
			&& token->quote[idx] == '1')
		{
			token->val[idx] = 0;
			tmp_val = ft_strjoin(token->val, token->val + idx + 1);
			free(token->val);
			token->val = tmp_val;
			token->quote[idx] = 0;
			tmp_quote = ft_strjoin(token->quote, token->quote + idx + 1);
			free(token->quote);
			token->quote = tmp_quote;
			idx--;
			if (token->type == 'h')
				token->type = 'H';
		}
		idx++;
	}
}

void	removing_quote(t_token **token)
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
		record_quote(now);
		before = now;
		now = now->next;
	}
	now = *token;
	while (now != 0)
	{
		if (now->type != 'r')
			remove_quote(now);
		now = now->next;
	}
}
