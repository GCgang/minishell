/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_search2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:47:29 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/04 21:41:26 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pars.h"

static int	free_str(char **del_0, char **del_1)
{
	if (*del_0 != 0)
		free(*del_0);
	if (*del_1 != 0)
		free(*del_1);
	return (1);
}

static int	search_ifs(t_token **token, int *len, char ifs)
{
	*len = 0;
	while ((*token)->val && (*token)->val[*len])
	{
		if ((*token)->val[*len] == ifs)
			return (0);
		(*len)++;
	}
	return (1);
}

static int	search_token(t_token **token, int len, char ifs)
{
	t_token	*new;
	t_token	*next;
	char	*new_val;

	new_val = ft_strdup(" ");
	if (new_val == 0)
		return (1);
	new = lstnew_token('t', new_val);
	next = (*token)->next;
	(*token)->next = new;
	new_val = ft_substr((*token)->val, len + 1, ft_strlen((*token)->val));
	if (new_val == 0)
		return (1);
	new = lstnew_token('w', new_val);
	(*token)->next->next = new;
	new->next = next;
	new_val = (*token)->val;
	(*token)->val = ft_substr(new_val, 0, len);
	if ((*token)->val == 0)
		return (1);
	free(new_val);
	if (search_ifs(&new, &len, ifs) == 0)
		return (search_token(&new, len, ifs));
	return (0);
}

int	trim_env_token(t_token *token, t_env *env_list, int **loca)
{
	int		idx;
	int		len;
	char	ifs;

	idx = loca[0][0];
	len = loca[0][0] + loca[0][2];
	ifs = ' ';
	while (env_list)
	{
		if (!ft_strncmp(env_list->name, "IFS", 4))
			ifs = env_list->val[0];
		env_list = env_list->next;
	}
	while (idx < len && token->val[idx])
	{
		if (token->val[idx] == ifs)
			return (search_token(&token, idx, ifs));
		idx++;
	}
	return (0);
}

int	trans_env_token(t_token *token, char **tgt, int **loca, int flag)
{
	char	*tmp;
	char	*tmp2;

	if (flag == 0 && token->next && token->next->val[0] == '\"'
		&& ((*tgt)[0] == '$' || (*tgt)[0] == '\0'))
		(*tgt)[0] = 0;
	loca[0][2] = ft_strlen(*tgt);
	token->val[loca[0][0]] = 0;
	if (token->val[0] == 0)
		tmp = ft_strdup(*tgt);
	else
		tmp = ft_strjoin(token->val, *tgt);
	if (tmp == 0)
		return (1);
	tmp2 = ft_strdup(token->val + loca[0][1]);
	if (tmp2 == 0)
		return (free_str(&tmp, 0));
	if (token->val != 0)
		free(token->val);
	token->val = ft_strjoin(tmp, tmp2);
	if (token->val == 0)
		return (free_str(&tmp, &tmp2));
	free_str(&tmp, &tmp2);
	free(*tgt);
	return (0);
}
