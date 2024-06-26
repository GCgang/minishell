/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_cnt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:51:58 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/10 20:55:15 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pars.h"

static void	word_del(t_token **token, t_token **now, t_token **before)
{
	if (*token == *now)
	{
		*token = (*now)->next;
		lstdelone_token(*now);
		*now = *token;
	}
	else
	{
		(*before)->next = (*now)->next;
		lstdelone_token(*now);
		*now = (*before)->next;
	}
}

static int	word_array(t_token **token, t_command *com)
{
	int		idx;
	t_token	*now;
	t_token	*before;

	idx = 0;
	before = *token;
	now = *token;
	while (now != 0 && now->type != 'p')
	{
		if (now->type == 'w')
		{
			com->word[idx] = ft_strdup(now->val);
			if (com->word[idx] == 0)
				return (err_msg("Error : Malloc failed(word_array)", 1, 0));
			word_del(token, &now, &before);
			idx++;
		}
		else
		{
			before = now;
			now = now->next;
		}
	}
	return (0);
}

static int	chk_cnt(t_token **token)
{
	t_token	*tmp;
	int		cnt;

	tmp = *token;
	cnt = 0;
	while (tmp != 0 && tmp->type != 'p')
	{
		if (tmp->type == 'r')
		{
			tmp = tmp->next;
			if (tmp != 0 && tmp->type == 'w')
				tmp->type = 'v';
		}
		else
			cnt++;
		if (tmp != 0)
			tmp = tmp->next;
	}
	return (cnt);
}

int	word_cnt(t_token **token, t_command *com)
{
	int		cnt;

	cnt = chk_cnt(token);
	if (cnt != 0)
	{
		com->word = (char **)malloc(sizeof(char *) * (cnt + 1));
		if (com->word == 0)
			return (err_msg("Error : Malloc failed(word_cnt)", 1, 0));
		com->word[cnt] = 0;
		if (word_array(token, com))
			return (1);
	}
	return (0);
}
