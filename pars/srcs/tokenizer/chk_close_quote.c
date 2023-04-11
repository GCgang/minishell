/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_close_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:19 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/07 17:21:41 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pars.h"

static int	chk_quote(char *line, int *idx, char quote)
{
	if (line[*idx] == quote)
	{
		(*idx)++;
		while (line[*idx] != quote && line[*idx] != 0)
			(*idx)++;
		if (line[*idx] != quote)
		{
			err_msg("Minishell: Syntax error unclosed quote", 1, 0);
			g_exit_status = 2;
			return (2);
		}
		(*idx)++;
		return (1);
	}
	return (0);
}

static void	chk_none_quote(char *line, int *idx)
{
	if (line[*idx] != 0 && line[*idx] != '\'' && line[*idx] != '\"')
		(*idx)++;
}

int	chk_close_quote(char *line)
{
	int	idx;

	idx = 0;
	if (!line[0])
		return (0);
	while (line[idx] != 0)
	{
		if (chk_quote(line, &idx, '\'') == 2)
			return (0);
		if (chk_quote(line, &idx, '\"') == 2)
			return (0);
		chk_none_quote(line, &idx);
	}
	return (1);
}
