#include "../include/pars.h"

/*
	split_sord_ifs
	1. 환경 변수로 등록되어 있는 단어 구분자를 찾을 때 사용
	2. search_ifs : 메타문자, 인용문구 제외, 문자열로 치환한 환경변수 내용물을 확인하여 구분자가 존재하는 경우, 구분자 기준 토큰을 분할
		2-a. 분할된 토큰은 'w'(word)로 구분한다
	3. split_ifs : 구분자로 분할하여 신규 토큰 작성이 필요할 시, 사용
*/
static int	split_ifs(t_token *tmp, char *ifs, int *idx)
{
	char	*tmp_str;
	t_token	*new_tkn;
	int		final;

	final = *idx;
	tmp->val[*idx] = 0;
	tmp->quote[*idx] = 0;
	while (ft_strchr(ifs, tmp->val[++final]) != 0 && tmp->val[final] != 0)
		;
	new_tkn = lstnew_token('w', ft_strdup(&(tmp->val[final])));
	new_tkn->quote = ft_strdup(&(tmp->quote[final]));
	new_tkn->next = tmp->next;
	tmp->next = new_tkn;
	tmp_str = ft_strdup(tmp->val);
	free(tmp->val);
	tmp->val = tmp_str;
	tmp_str = ft_strdup(tmp->quote);
	free(tmp->quote);
	tmp->quote = tmp_str;
	return (1);
}

static void	search_ifs(t_token **token, char *ifs)
{
	t_token	*tmp;
	int		idx;

	tmp = *token;
	while (tmp != 0 && tmp->type != 'p')
	{
		idx = -1;
		if (tmp->type != 'r' && tmp->type != 'h')
		{
			while (tmp->val[++idx] != 0)
			{
				if (tmp->val[idx] == '\'' && tmp->quote[idx] == '1')
					while (!(tmp->val[++idx] == '\'' && tmp->quote[idx] == '1'))
						;
				else if (tmp->val[idx] == '\"' && tmp->quote[idx] == '1')
					while (!(tmp->val[++idx] == '\"' && tmp->quote[idx] == '1'))
						;
				else if (ft_strchr(ifs, tmp->val[idx]) != 0
					&& tmp->quote[idx] == '2' && split_ifs(tmp, ifs, &idx))
					break ;
			}
		}
		tmp = tmp->next;
	}
}

void	split_word_ifs(t_token **token, t_env *env_list)
{
	while (env_list != 0)
	{
		if (ft_strncmp(env_list->name, "IFS", 4) == 0)
			break ;
		env_list = env_list->next;
	}
	if (env_list != 0)
		search_ifs(token, env_list->val);
}
