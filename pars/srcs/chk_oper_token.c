/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_oper_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:24 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/22 14:01:31 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pars.h"

/*
	chk_oper_token
	1. 메타 문자로 구성된 토큰 유형을 r과 p로 분류
	2. 메타 문자가 연속으로 이어지거나 지원하지 않는 메타 문자인 경우, 기대되지 않는 토큰이 나왔다는 오류를 출력

	처리 필요
	1. error 시, env_list exit_status = 258로 변경
*/

int	chk_meta_token_err(t_token *token)
{
	char	*tmp;

	if (token->type == 't' || token->next == 0
		|| (token->next != 0 && token->next->type == 't'))
	{
		if (token->next == 0)
			tmp = ft_strdup("newline");
		else if (token->next != 0 && token->next->type == 't')
			tmp = ft_strdup(token->next->val);
		else
			tmp = ft_strdup(token->val);
		printf("Minishell: Syntax error near unexpected token '%s'\n",
			tmp);
		free(tmp);
		return (1);
	}
	return (0);
}

int	chk_oper_token(t_token *token)
{
	if (token->type == 't' && token->val[0] == '|')
	{
		printf("Minishell: Syntax error near unexpected token '%s'\n",
			token->val);
		return (1);
	}
	while (token != 0)
	{
		if (token->type == 't')
		{
			if (token->val[0] == '>' || token->val[0] == '<')
				token->type = 'r';
			else if (token->val[0] == '|')
				token->type = 'p';
			if (chk_meta_token_err(token))
				return (1);
		}
		token = token->next;
	}
	return (0);
}
