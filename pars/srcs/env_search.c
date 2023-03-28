/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:30 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/24 18:40:38 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
static void	trim_env_token(t_token *token, t_env *env_list, int **loca)
{
	int		idx;
	int		len;
	char	ifs;

	idx = loca[0][0];
	len = loca[0][0] + loca[0][2];
	ifs = ' ';
	while (env_list)
	{
		if (ft_strncmp(env_list->name, "IFS", 4) == 0)
			ifs = env_list->val[0];
		env_list = env_list->next;
	}
	while (idx < len && token->val[idx])
	{
		if (token->val[idx] == ifs)
		{
			token->val[idx] = 0;
			return ;
		}
		idx++;
	}
}

static void	trans_env_token(t_token *token, char **tgt, int **loca)
{
	char	*tmp;
	char	*tmp2;

	if (token->next && token->next->val[0] == '\"')
		(*tgt)[0] = 0;
	loca[0][2] = ft_strlen(*tgt);
	token->val[loca[0][0]] = 0;
	if (token->val[0] == 0)
		tmp = ft_strdup(*tgt);
	else
		tmp = ft_strjoin(token->val, *tgt);
	tmp2 = ft_strdup(token->val + loca[0][1]);
	token->val = ft_strjoin(tmp, tmp2);
	if (tmp != 0)
		free(tmp);
	if (tmp2 != 0)
		free(tmp2);
	if (*tgt != 0)
		free(*tgt);
	if (!ft_strncmp(token->val, "\"\"", 3) || !(token->val[0]))
		(loca[0][0])--;
}

static void	chk_env_token(t_token *token, t_env *env_list, int **loca, int q)
{
	char	*tmp;

	loca[0][1] = loca[0][0] + 1;
	while (ft_strchr(" $\n\t\"\'=/\\", token->val[loca[0][1]]) == 0)
		(loca[0][1])++;
	tmp = ft_substr(token->val, loca[0][0] + 1, loca[0][1] - loca[0][0] - 1);
	while (env_list)
	{
		if (!ft_strncmp(tmp, env_list->name, ft_strlen(env_list->name) + 1))
			break ;
		env_list = env_list->next;
	}
	free(tmp);
	if (env_list != 0)
		tmp = ft_strdup(env_list->val);
	else
	{
		if (!token->val[loca[0][0] + 1])
			tmp = ft_strdup("$");
		else
			tmp = ft_strdup("");
	}
	trans_env_token(token, &tmp, loca);
	if (q == 0 && token->val[0] && ft_strncmp(token->val, "\"\"", 3))
		trim_env_token(token, env_list, loca);
}

int	env_search(t_token *token, t_env *env_list)
{
	int	*loca;

	loca = (int *)malloc(sizeof(int) * 3);
	if (!loca)
		return (1);
	loca[0] = 0;
	while (token->val != 0 && token->val[loca[0]])
	{
		if (token->val[loca[0]] == '\'')
			while (token->val[++(loca[0])] != '\'')
				;
		else if (token->val[loca[0]] == '\"')
		{
			while (token->val[++(loca[0])] != '\"')
				if (token->val[loca[0]] == '$')
					chk_env_token(token, env_list, &loca, 1);
		}
		else
		{
			if (token->val[loca[0]] == '$')
				chk_env_token(token, env_list, &loca, 0);
		}
		(loca[0])++;
	}
	free(loca);
	return (0);
}
