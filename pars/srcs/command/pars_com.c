/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:54 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/12 20:09:14 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pars.h"

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
				return (err_msg("Error : Malloc failed(input_redir)", 1, 0));
		}
		else
		{
			com->redir_val[idx] = ft_strdup((*token)->val);
			if (com->redir_val[idx] == 0)
				return (err_msg("Error : Malloc failed(input_redir)", 1, 0));
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
		return (err_msg("Error : Malloc failed(malloc_redir)", 1, 0));
	com->redir[cnt] = 0;
	com->redir_val = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (com->redir_val == 0)
		return (err_msg("Error : Malloc failed(malloc_redir)", 1, 0));
	com->redir_val[cnt] = 0;
	return (0);
}

static int	redir_cnt(t_token **token)
{
	int		redir_cnt;
	int		redir_val_cnt;
	t_token	*tmp;

	tmp = *token;
	redir_cnt = 0;
	redir_val_cnt = 0;
	while (tmp != 0 && tmp->type != 'p')
	{
		if (tmp->type == 'r')
			redir_cnt++;
		else if (tmp->type == 'v')
			redir_val_cnt++;
		tmp = tmp->next;
	}
	if (redir_cnt != redir_val_cnt)
		return (-1);
	return (redir_cnt);
}

int	pars_com(t_token **token, t_command *com)
{
	int	cnt;

	cnt = 0;
	cnt = redir_cnt(token);
	if (cnt == -1)
		return (1);
	if (malloc_redir(com, cnt) || input_redir(com, token))
		return (1);
	return (0);
}
