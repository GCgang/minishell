#include "../include/pars.h"

/*
	trim_token : 각 토큰에서 불필요한 공백을 제거하고 공백으로만 이루어진 토큰도 제거(인용 제외)
	1. trim_blank : 각 토큰마다 양 끝단에 위치한 불필요한 공백 제거(인용 제외)
	2. split_token : 메타 문자 집합으로 된 토큰에서 공백을 분리한다
	3. split_oper_token : 공백을 제거한 메타 문자들을 개별로 분리한다
	4. 분리한 공백은 전부 제거

	error 수정 필요
	1. w와 w 사이에 'b'가 없으면 두 토큰을 붙이고 한 토큰 삭제
*/
t_token	*connect_newlst(t_token *tmp, char *val)
{
	t_token	*new;

	new = lstnew_token('t', val);
	new->next = tmp->next;
	return (new);
}

static void	split_oper_token(t_token **token)
{
	t_token	*tmp;

	tmp = *token;
	while (tmp != 0)
	{
		if (tmp->type == 't' && ft_strlen(tmp->val) > 1)
		{
			if (ft_strlen(tmp->val) != 2
				&& ((tmp->val[0] == '<' && tmp->val[1] == '<')
					|| (tmp->val[0] == '>' && tmp->val[1] == '>')))
				extend_trim_token(tmp, 2);
			else if (!((tmp->val[0] == '<' && tmp->val[1] == '<')
					|| (tmp->val[0] == '>' && tmp->val[1] == '>')))
				extend_trim_token(tmp, 1);
		}
		tmp = tmp->next;
	}
}

static void	split_token(t_token **token)
{
	t_token	*tmp;
	char	**arr;
	int		idx;

	tmp = *token;
	idx = 0;
	while (tmp != 0)
	{
		if (tmp->type == 't' && ft_strchr(tmp->val, ' ') != 0)
		{
			arr = ft_split(tmp->val, ' ');
			tmp->type = 'b';
			while (arr[idx] != 0)
			{
				tmp->next = connect_newlst(tmp, arr[idx]);
				tmp = tmp->next;
				idx++;
			}
			if (arr != 0)
				free(arr);
		}
		tmp = tmp->next;
	}
	split_oper_token(token);
}

static void	trim_blank(t_token *token)
{
	char	*tmp;

	while (token != 0)
	{
		tmp = ft_strtrim(token->val, " ");
		free(token->val);
		token->val = tmp;
		token = token->next;
	}
}

void	trim_token(t_token **token)
{
	t_token	*before;
	t_token	*now;

	now = *token;
	trim_blank(*token);
	split_token(token);
	while (now != 0)
	{
		if (((ft_strlen(now->val) == 0) || now->type == 'b')
			&& now == *token)
		{
			*token = now->next;
			lstdelone_token(now, &free);
			now = *token;
		}
		else if ((now->next != 0) && ((ft_strlen(now->next->val) == 0)
				|| now->next->type == 'b'))
		{
			before = now->next;
			now->next = now->next->next;
			lstdelone_token(before, &free);
		}
		else if (now != 0)
			now = now->next;
	}
}
