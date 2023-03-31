/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:11:28 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/31 19:11:29 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static t_env	*conv_env(char *front, char *back)
{
	char	*name;
	char	*val;
	t_env	*node;

	name = ft_strdup(front);
	if (name == 0)
		return (0);
	val = ft_strdup(back);
	if (val == 0)
	{
		free(name);
		return (0);
	}
	node = lstnew_env(name, val);
	return (node);
}

int	init_env(char **envp, t_env **env_list)
{
	int		idx;
	char	*equal;
	t_env	*node;

	idx = 0;
	*env_list = 0;
	while (envp[idx] != 0)
	{
		equal = ft_strchr(envp[idx], '=');
		*equal = 0;
		if (ft_strncmp(envp[idx], "OLDPWD", 7) != 0)
		{
			node = conv_env(envp[idx], equal + 1);
			if (node == 0)
				return (0);
			lstadd_back_env(env_list, node);
		}
		idx++;
	}
	node = conv_env("OLDPWD", 0);
	if (node == 0)
		return (0);
	lstadd_back_env(env_list, node);
	return (1);
}
