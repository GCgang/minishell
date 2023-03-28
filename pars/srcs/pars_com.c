/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:54 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/28 14:16:48 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pars.h"

static int	input_redir(t_command *com, t_token **token)
{
	t_token	*tmp;
	int		idx;

	idx = 0;
	while (*token != 0 && (*token)->type != 'p')
	{
		if ((*token)->type == 'r')
		{
			com->redir[idx] = ft_strdup((*token)->val);
			if (com->redir[idx] == 0)
				return (1);
		}
		else
		{
			com->redir_val[idx] = ft_strdup((*token)->val);
			if (com->redir_val[idx] == 0)
				return (1);
			idx++;
		}
		tmp = (*token);
		*token = (*token)->next;
		lstdelone_token(tmp);
	}
	return (0);
}

static int	malloc_redir(t_command *com, int cnt)
{
	com->redir = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (com->redir == 0)
		return (1);
	com->redir[cnt] = 0;
	com->redir_val = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (com->redir_val == 0)
		return (1);
	com->redir_val[cnt] = 0;
	return (0);
}

static int	redir_cnt(t_token **token)
{
	int		cnt;
	t_token	*tmp;

	cnt = 0;
	tmp = *token;
	while (tmp != 0 && tmp->type != 'p')
	{
		if (tmp->type == 'r')
			cnt++;
		tmp = tmp->next;
	}
	return (cnt);
}

int	pars_com(t_token **token, t_command *com)
{
	int	cnt;

	cnt = redir_cnt(token);
	if (malloc_redir(com, cnt) || input_redir(com, token))
		return (1);
	return (0);
}
