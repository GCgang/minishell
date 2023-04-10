/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_search3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:30:14 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/10 12:59:20 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pars.h"

static void	chk_ifs_token(t_token **token, char *ifs)
{
	if (ifs[(int) ' '] == '1' || ifs[(int) '\n'] == '1'
		|| ifs[(int) '\t'] == '1')
	{
		if ((*token)->val[0] == 0)
			(*token)->type = 't';
	}
}

static void	setting_ifs(char *ifs, char *tgt)
{
	int	idx;

	idx = 0;
	if (!tgt || !ifs)
		return ;
	while (idx < 256)
	{
		ifs[idx] = '0';
		idx++;
	}
	if (tgt[0] == 0)
	{
		ifs[0] = '1';
		return ;
	}
	idx = 0;
	while (tgt && tgt[idx])
	{
		ifs[(int)(tgt[idx])] = '1';
		idx++;
	}
}

static int	search_ifs(t_token **token, int *cur, int len, char *ifs)
{
	int	idx;

	idx = 0;
	if (!*token)
		return (-1);
	while ((*token)->val && (*token)->val[idx] && (len > idx + *cur))
	{
		if (ifs[(int)((*token)->val[idx])] == '1')
		{
			if ((*token)->val[idx + 1] == 0)
			{
				(*token)->val[idx] = 0;
				return (-1);
			}
			return (idx);
		}
		idx++;
	}
	return (-1);
}

static t_token	*search_token(t_token **token, int len, char *ifs)
{
	t_token	*new;
	t_token	*next;
	char	*new_val;

	if (*token == 0)
		return (0);
	new_val = ft_strdup(" ");
	if (new_val == 0)
		return (0);
	new = lstnew_token('t', new_val);
	next = (*token)->next;
	(*token)->next = new;
	new_val = ft_substr((*token)->val, len + 1, ft_strlen((*token)->val));
	if (new_val == 0)
		return (0);
	new = lstnew_token('w', new_val);
	(*token)->next->next = new;
	new->next = next;
	new_val = (*token)->val;
	(*token)->val = ft_substr(new_val, 0, len);
	if ((*token)->val == 0)
		return (0);
	chk_ifs_token(token, ifs);
	free(new_val);
	return (new);
}

void	trim_env_token(t_token *token, t_env *env_list, int **loca)
{
	int		idx;
	int		len;
	int		cur;
	char	ifs[256];

	idx = loca[0][0];
	len = loca[0][0] + loca[0][2];
	setting_ifs(ifs, " \n\t");
	while (env_list)
	{
		if (!ft_strncmp(env_list->name, "IFS", 4))
			setting_ifs(ifs, env_list->val);
		env_list = env_list->next;
	}
	while (idx < len)
	{
		cur = search_ifs(&token, &idx, len, ifs);
		if (cur != -1)
			token = search_token(&token, cur, ifs);
		else
			idx++;
	}
	if (token && token->type == 'w' && token->val[0] == 0)
		token->type = 't';
}
