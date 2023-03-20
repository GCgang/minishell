#include "../include/pars.h"

/*
	env_search
	1. 인용문구를 찾는다. 작은 따옴표는 환경변수 무시이므로 넘김.
	2. 큰 따옴표나 아예 따옴표가 없는데 $가 나오는 경우, 환경변수 분석.
	   단, heredoc의 경우, 환경변수 자체도 문자열로 받아 들이기에 별도 해석 X
	3. conv_env_to_token : $뒤의 이름을 파싱하고 동명의 환경변수가 존재하는 지 확인
	4. make_env_name&val : 해당 환경변수가 없는 경우, 아예 빈 환경변수를 만들어 final로 보낸다
	5. conv_env_final : 환경변수의 내용물을 토큰에 집어 넣는다
*/
static void	conv_env_final(t_token *tkn, t_env *e_list, int start, int final)
{
	char	*tmp_val;
	char	*tmp_blank;
	char	*tmp_str;

	tmp_val = ft_strdup(e_list->val);
	tkn->val[start] = 0;
	tmp_str = ft_strjoin(tkn->val, tmp_val);
	free(tmp_val);
	tmp_val = ft_strjoin(tmp_str, tkn->val + final);
	free(tmp_str);
	free(tkn->val);
	tkn->val = tmp_val;
	tmp_blank = (char *)malloc(sizeof(char) * (ft_strlen(e_list->val) + 1));
	if (tmp_blank == 0)
		return ;
	tmp_blank[ft_strlen(e_list->val)] = 0;
	ft_memset(tmp_blank, '2', ft_strlen(e_list->val));
	tkn->quote[start] = 0;
	tmp_str = ft_strjoin(tkn->quote, tmp_blank);
	free(tmp_blank);
	tmp_blank = ft_strjoin(tmp_str, tkn->quote + final);
	free(tmp_str);
	free(tkn->quote);
	tkn->quote = tmp_blank;
}

static void	make_env_val(t_token *tkn, t_env *tmp, int *start, int final)
{
	if ((final - *start) == 1 && (tmp->name[0] == '1'
			|| (tkn->val[final] != '\"' && tkn->val[final] != '\'')))
		tmp->val = (char *)malloc(sizeof(char) * 2);
	else
		tmp->val = (char *)malloc(sizeof(char));
	if (tmp->val == 0)
		return ;
	if ((final - *start) == 1 && (tmp->name[0]
			|| (tkn->val[final] != '\"' && tkn->val[final] != '\'')))
	{
		tmp->val[0] = '$';
		tmp->val[1] = 0;
	}
	else
		tmp->val[0] = 0;
	tmp->next = 0;
}

static void	make_env_name(t_token *tkn, int *start, int final, int q)
{
	t_env	*tmp;

	tmp = (t_env *)malloc(sizeof(t_env));
	if (tmp == 0)
		return ;
	tmp->name = (char *)malloc(sizeof(char) * 2);
	if (tmp->name == 0)
		return ;
	if (q == 1)
		tmp->name[0] = '1';
	else
		tmp->name[0] = '0';
	tmp->name[1] = 0;
	make_env_val(tkn, tmp, start, final);
	conv_env_final(tkn, tmp, *start, final);
	if (!((final - *start) == 1 && (tmp->name[0] == '1'
				|| (tkn->val[final] == '\"' && tkn->val[final] == '\''))))
		*start = *start - 1;
	lstdelone_env(tmp, &free);
}

static void	conv_env_to_token(t_token *tkn, t_env *e_list, int *start, int q)
{
	char	*tmp;
	int		final;

	final = *start + 1;
	while (ft_strchr(" $\t\n\"\'/=", tkn->val[final]) == 0)
		final++;
	tmp = ft_substr(tkn->val, *start + 1, final - *start - 1);
	printf("env : %s\n", tmp);
	while (e_list != 0)
	{
		if (ft_strncmp(e_list->name, tmp, ft_strlen(tmp) + 1) == 0)
			break ;
		e_list = e_list->next;
	}
	if (tmp[0] == 0)
	{
		free(tmp);
		return ;
	}
	free(tmp);
	if (e_list != 0)
		conv_env_final(tkn, e_list, *start, final);
	else
		make_env_name(tkn, start, final, q);
}

void	env_search(t_token *token, t_env *env_list)
{
	int	idx;

	idx = -1;
	while (token->val[++idx] != 0)
	{
		if (token->val[idx] == '\'')
		{
			idx++;
			while (token->val[idx] != '\'' && token->val[idx] != 0)
				idx++;
		}
		else if (token->val[idx] == '\"')
		{
			while (token->val[++idx] != '\"')
				if (token->val[idx] == '$')
					conv_env_to_token(token, env_list, &idx, 1);
		}
		else if (token->val[idx] == '$')
			conv_env_to_token(token, env_list, &idx, 0);
	}
}
