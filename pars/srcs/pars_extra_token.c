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
	while (token->val[*idx] != tgt)
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
	while (token != 0 && token->val[idx] != 0)
	{
		if (token->val[idx] == '\'')
			chk_quote(token, '\'', &idx);
		else if (token->val[idx] == '\"')
			chk_quote(token, '\"', &idx);
		else
			token->quote[idx] = '0';
		idx++;
	}
}

void	pars_extra_token(t_token **token, t_env *env_list)
{
	t_token	*now;
	t_token	*before;

	now = *token;
	before = now;
	while (now != 0 && now->type != 'p')
	{
		if (before != now && before->type == 'r'
			&& ft_strncmp(before->val, "<<", 3) == 0)
			now->type = 'h';
		record_quote(now);
		if (now->type != 'h')
			env_search(now, env_list);
		before = now;
		now = now->next;
	}
	split_word_ifs(token, env_list);
	now = *token;
	while (now != 0 && now->type != 'p')
	{
		if (now->type != 'r')
			remove_quote(now);
		now = now->next;
	}
}