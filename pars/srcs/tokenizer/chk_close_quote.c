/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_have_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:19 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/29 19:55:59 by jaehjoo          ###   ########.fr       */
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
			err_msg("Error : Don't have closed quote");
			return (-42);
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
		if (chk_quote(line, &idx, '\'') == -42)
			return (0);
		if (chk_quote(line, &idx, '\"') == -42)
			return (0);
		chk_none_quote(line, &idx);
	}
	return (1);
}
