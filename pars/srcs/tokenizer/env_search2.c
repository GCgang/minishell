/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_search2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:47:29 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/31 19:43:58 by jaehjoo          ###   ########.fr       */
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

void	trim_env_token(t_token *token, t_env *env_list, int **loca)
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
		{
			token->val[idx] = 0;
			return ;
		}
		idx++;
	}
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
