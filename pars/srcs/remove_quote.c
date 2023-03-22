#include "../include/pars.h"

/*
	remove_quote
	1. 메타문자를 제외한 나머지 word 토큰에서 따옴표를 제거한다
*/
void	remove_quote(t_token *token)
{
	int		idx;
	char	*tmp_val;
	char	*tmp_quote;

	idx = 0;
	while (token->val[idx] != 0)
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
