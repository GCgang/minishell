/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:30 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/07 21:59:08 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pars.h"

static char	*find_special_env(t_token *token, int **loca)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_substr(token->val, loca[0][0], loca[0][1] - loca[0][0]);
	if (!tmp)
		return (0);
	tmp2 = tmp;
	if (ft_strncmp(tmp2, "$?", 3) == 0)
		tmp = ft_itoa(g_exit_status);
	else if (!tmp2[1])
		tmp = ft_strdup("$");
	else
		tmp = ft_strdup("");
	free(tmp2);
	if (!tmp)
		return (0);
	return (tmp);
}

static t_env	*compare_env_token(char *token, t_env *env_list)
{
	while (env_list)
	{
		if (!ft_strncmp(token, env_list->name, ft_strlen(env_list->name) + 1))
			break ;
		env_list = env_list->next;
	}
	return (env_list);
}

static int	is_env(t_token *token, t_env *env_list, int **loca, int flag)
{
	char	*tmp;

	loca[0][1] = loca[0][0] + 1;
	if (token->val[loca[0][1]]
		&& ft_strchr("$*?@#-!0123456789", token->val[loca[0][1]]))
		(loca[0][1])++;
	else
		while (token->val[loca[0][1]] && !ft_strchr(" :\n\t$*?@#-!\"\'/|&;(){}[]",
					token->val[loca[0][1]]))
			(loca[0][1])++;
	tmp = ft_substr(token->val, loca[0][0] + 1, loca[0][1] - loca[0][0] - 1);
	if (tmp == 0)
		return (err_msg("Error : Malloc failed(is_env)", 1, loca));
	env_list = compare_env_token(tmp, env_list);
	free(tmp);
	if (env_list != 0)
		tmp = ft_strdup(env_list->val);
	else
		tmp = find_special_env(token, loca);
	if (tmp == 0)
		return (err_msg("Error : Malloc failed(is_env)", 1, loca));
	if (trans_env_token(token, &tmp, loca, flag))
		return (err_msg("Error : Malloc failed(trans_env_token)", 1, loca));
	return (0);
}

static int	find_icon(char *tgt, int **loca)
{
	if (tgt[loca[0][0]] == '\'')
	{
		(loca[0][0])++;
		while (tgt[loca[0][0]] != 0 && tgt[loca[0][0]] != '\'')
			(loca[0][0])++;
	}
	else if (tgt[loca[0][0]] == '\"')
	{
		(loca[0][0])++;
		while (tgt[loca[0][0]] != 0 && tgt[loca[0][0]] != '\"')
		{
			if (tgt[loca[0][0]] == '$')
				return (1);
			(loca[0][0])++;
		}
	}
	else if (tgt[loca[0][0]] != 0 && tgt[loca[0][0]] != '\"')
	{
		if (tgt[loca[0][0]] == '$')
			return (0);
	}
	return (2);
}

int	env_search(t_token *token, t_env *env_list)
{
	int	*loca;
	int	flag;

	loca = (int *)malloc(sizeof(int) * 3);
	if (!loca)
		return (err_msg("Error : Malloc failed(env_search)", 1, 0));
	loca[0] = 0;
	while (token->val != 0 && token->val[loca[0]])
	{
		flag = find_icon(token->val, &loca);
		if (flag == 0 || flag == 1)
			if (is_env(token, env_list, &loca, flag))
				return (1);
		if (flag == 0 && token->val[0] && ft_strncmp(token->val, "\"\"", 3))
			trim_env_token(token, env_list, &loca);
		if (token->val[loca[0]] != 0)
			(loca[0])++;
	}
	free(loca);
	return (0);
}
