/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:50 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/05 20:15:15 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pars.h"

static int	input_token(char *now, t_token **token, int *len, char *spe)
{
	t_token	*tmp;
	char	*val;

	if (now != 0 && *len != 0)
	{
		val = (char *)malloc(sizeof(char) * (*len + 1));
		if (!val)
			return (1);
		ft_strlcpy(val, now, *len + 1);
		if (ft_strchr(spe, now[0]) != 0)
			tmp = lstnew_token('t', val);
		else if (now[0] == '$')
			tmp = lstnew_token('e', val);
		else
			tmp = lstnew_token('w', val);
		if (!tmp)
			return (err_msg("Error : Malloc failed(input_token)"));
		lstadd_back_token(token, tmp);
		now = 0;
		*len = 0;
	}
	return (0);
}

static char	*quote(char *line, int *idx, int *len, char quote)
{
	if (line[*idx] == quote)
	{
		(*len)++;
		(*idx)++;
		while (line[*idx] != quote && line[*idx] != 0)
		{
			(*len)++;
			(*idx)++;
		}
		(*len)++;
		(*idx)++;
		return (line + *idx - *len);
	}
	return (0);
}

static char	*sep_none_quote(char *line, int *idx, int *len)
{
	if (line[*idx] != 0 && line[*idx] != '\'' && line[*idx] != '\"')
	{
		if (line[*idx] == '\n' || line[*idx] == '\t')
			line[*idx] = ' ';
		(*idx)++;
		(*len)++;
	}
	return (line + *idx - *len);
}

int	make_token(char *line, char *spe, t_token **token)
{
	int		idx;
	int		len;
	char	*now;

	idx = 0;
	len = 0;
	now = 0;
	while (line[idx] != 0)
	{
		now = quote(line, &idx, &len, '\'');
		if (input_token(now, token, &len, spe))
			return (1);
		now = quote(line, &idx, &len, '\"');
		if (input_token(now, token, &len, spe))
			return (1);
		now = sep_none_quote(line, &idx, &len);
		if (len == 1)
		{
			if (input_token(now, token, &len, spe))
				return (1);
		}
	}
	return (0);
}
