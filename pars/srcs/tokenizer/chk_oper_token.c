/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_oper_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:24 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/05 20:02:25 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pars.h"

int	chk_meta_token_err(t_token *token)
{
	char	*tmp;

	if (token->type == 't' || token->next == 0
		|| (token->next != 0 && token->next->type == 't'
			&& token->next->val[0] != '<' && token->next->val[0] != '>'))
	{
		if (token->next == 0 || (token->val[0] == '('
				&& (token->next->val[0] == '<' || token->next->val[0] == '>')))
			tmp = ft_strdup("newline");
		else if (token->next != 0 && token->next->type == 't')
			tmp = ft_strdup(token->next->val);
		else
			tmp = ft_strdup(token->val);
		g_exit_status = 2;
		printf("Minishell: Syntax error near unexpected token '%s'\n",
			tmp);
		if (tmp != 0)
			free(tmp);
		return (1);
	}
	return (0);
}

int	chk_oper_token(t_token *token)
{
	if (token != 0 && token->type == 't'
		&& ft_strchr("|&;", token->val[0]) != 0)
	{
		g_exit_status = 2;
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
