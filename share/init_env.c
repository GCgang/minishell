/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:11:28 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/07 21:49:34 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static int	ft_stridx(char *str, char tgt)
{
	int	idx;

	idx = -1;
	if (!str)
		return (-1);
	while (str[++idx])
	{
		if (str[idx] == tgt)
			break ;
	}
	return (idx);
}

static t_env	*conv_env(char *tgt, int len)
{
	char	*name;
	char	*val;
	t_env	*node;

	name = ft_substr(tgt, 0, len);
	if (name == 0)
		return (0);
	if (!tgt[len])
		val = 0;
	else
	{
		val = ft_substr(tgt, len + 1, ft_strlen(tgt));
		if (val == 0)
		{
			free(name);
			return (0);
		}
	}
	node = lstnew_env(name, val);
	return (node);
}

int	init_env(char **envp, t_env **env_list)
{
	int		idx;
	int		len;
	t_env	*node;

	idx = 0;
	*env_list = 0;
	while (envp[idx] != 0)
	{
		len = ft_stridx(envp[idx], '=');
		if (len == -1)
			return (0);
		node = conv_env(envp[idx], len);
		if (node == 0)
			return (1);
		lstadd_back_env(env_list, node);
		idx++;
	}
	return (0);
}
