/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_search2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:47:29 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/07 17:28:24 by jaehjoo          ###   ########.fr       */
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

int	trans_env_token(t_token *token, char **tgt, int **loca, int flag)
{
	char	*tmp;
	char	*tmp2;

	if (flag == 0 && token->next && token->next->val[0] == '\"'
		&& *tgt != 0 && (*tgt)[0] == '$')
		(*tgt)[0] = 0;
	loca[0][2] = ft_strlen(*tgt);
	token->val[loca[0][0]] = 0;
	if (token->val[0] == 0)
		tmp = ft_strdup(*tgt);
	else
		tmp = ft_strjoin(token->val, *tgt);
	if (tmp == 0)
		return (err_msg("Error : Malloc failed(trans_env_token)", 1, 0));
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
