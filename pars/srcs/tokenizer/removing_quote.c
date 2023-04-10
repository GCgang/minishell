/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removing_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:57 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/10 14:03:03 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pars.h"

static void	chk_quote(t_token **token, char tgt, int *idx)
{
	t_token	*tmp;
	int		first;

	tmp = *token;
	tmp->quote[*idx] = '1';
	first = *idx;
	(*idx)++;
	while (tmp->val[*idx] != 0 && tmp->val[*idx] != tgt)
	{
		tmp->quote[*idx] = '0';
		(*idx)++;
	}
	if (tmp->val[*idx] != tgt)
		tmp->quote[first] = '0';
	else
		tmp->quote[*idx] = '1';
}

static int	record_quote(t_token **token)
{
	int		idx;
	t_token	*tmp;

	idx = 0;
	tmp = *token;
	tmp->quote = (char *)malloc(sizeof(char)
			* (ft_strlen(tmp->val) + 1));
	if (tmp->quote == 0)
		return (err_msg("Error : Malloc failed(record_quote)", 1, 0));
	while (tmp != 0 && tmp->val != 0 && tmp->val[idx] != 0)
	{
		tmp->quote[ft_strlen(tmp->val)] = 0;
		if (tmp->val[idx] == '\'')
			chk_quote(&tmp, '\'', &idx);
		else if (tmp->val[idx] == '\"')
			chk_quote(&tmp, '\"', &idx);
		else
			tmp->quote[idx] = '0';
		if (tmp->val[idx])
			idx++;
	}
	return (0);
}

static int	remove_quote(t_token **token)
{
	int		idx;
	char	*tmp;

	idx = -1;
	while ((*token)->val != 0 && (*token)->val[++idx] != 0)
	{
		if (((*token)->val[idx] == '\'' || (*token)->val[idx] == '\"')
			&& (*token)->quote[idx] == '1')
		{
			(*token)->val[idx] = 0;
			tmp = ft_strjoin((*token)->val, (*token)->val + idx + 1);
			if (tmp == 0)
				return (err_msg("Error : Malloc failed(remove_quote)", 1, 0));
			free((*token)->val);
			(*token)->val = tmp;
			(*token)->quote[idx] = 0;
			tmp = ft_strjoin((*token)->quote, (*token)->quote + idx + 1);
			if (tmp == 0)
				return (err_msg("Error : Malloc failed(remove_quote)", 1, 0));
			free((*token)->quote);
			(*token)->quote = tmp;
			idx--;
		}
	}
	return (0);
}

int	removing_quote(t_token **token)
{
	t_token	*now;

	now = *token;
	while (now != 0)
	{
		if (record_quote(&now))
			return (1);
		now = now->next;
	}
	now = *token;
	while (now != 0)
	{
		if (now->type != 'r')
			if (remove_quote(&now))
				return (1);
		now = now->next;
	}
	return (0);
}
