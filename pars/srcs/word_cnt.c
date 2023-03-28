/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_cnt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:51:58 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/28 14:29:00 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pars.h"

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

static void	word_array(t_token **token, t_command *com)
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
			word_del(token, &now, &before);
			idx++;
		}
		else
		{
			before = now;
			now = now->next;
		}
	}
}

void	word_cnt(t_token **token, t_command *com)
{
	int		cnt;
	t_token	*tmp;

	tmp = *token;
	cnt = 0;
	while (tmp != 0 && tmp->type != 'p')
	{
		if (tmp->type == 'r')
		{
			tmp = tmp->next;
			if (tmp != 0 && tmp->type == 'w')
				tmp->type = 'h';
		}
		else
			cnt++;
		if (tmp != 0)
			tmp = tmp->next;
	}
	if (cnt != 0)
	{
		com->word = (char **)malloc(sizeof(char *) * (cnt + 1));
		if (com->word == 0)
			return ;
		com->word[cnt] = 0;
		word_array(token, com);	
	}
}
