#include "../include/pars.h"

/*
	chk_oper_token
	1. 메타 문자로 구성된 토큰 유형을 r과 p로 분류
	2. 메타 문자가 연속으로 이어지거나 지원하지 않는 메타 문자인 경우, 기대되지 않는 토큰이 나왔다는 오류를 출력
*/
int	chk_oper_token(t_token *token)
{
	while (token != 0)
	{
		if (token->type == 't')
		{
			if (token->val[0] == '>' || token->val[0] == '<')
				token->type = 'r';
			else if (token->val[0] == '|')
				token->type = 'p';
			if (token->next->type == 't' || token->type == 't')
			{
				printf("Minishell: Syntax error near unexpected token '%s'\n"
					, token->next->val);
				return (1);
			}
		}
		token = token->next;
	}
	return (0);
}
