/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_oper_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:24 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/11 18:58:09 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pars.h"

static int	extra_msg(void)
{
	err_msg("Minishell: Syntax error near unexpected token ", 0, 0);
	g_exit_status = 2;
	return (err_msg("\'newline\'", 1, 0));
}

int	chk_meta_token_err(t_token *token)
{
	char	*tmp;

	if (token->type != 't' && !token->next)
		return (extra_msg());
	else if (token->type == 't' || token->next == 0
		|| (token->next != 0 && token->next->type == 't'
			&& !ft_strchr("<>", token->next->val[0])))
	{
		if (token->next == 0)
			tmp = ft_strdup("newline");
		else if (token->next != 0 && token->next->type == 't')
			tmp = ft_strdup(token->next->val);
		else
			tmp = ft_strdup(token->val);
		g_exit_status = 2;
		if (tmp == 0)
			return (err_msg("Error : Malloc failed(chk_meta_token_err)", 1, 0));
		err_msg("Minishell: Syntax error near unexpected token \'", 0, 0);
		err_msg(tmp, 0, 0);
		free(tmp);
		return (err_msg("\'", 1, 0));
	}
	return (0);
}

int	chk_oper_token(t_token *token)
{
	if (token != 0 && token->type == 't' && token->val[0] == '|')
	{
		g_exit_status = 2;
		err_msg("Minishell: Syntax error near unexpected token \'", 0, 0);
		err_msg(token->val, 0, 0);
		return (err_msg("\'", 1, 0));
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
