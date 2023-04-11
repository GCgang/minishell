/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:26:56 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/11 12:46:50 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_envp(t_env **env_list, char *name, char *val)
{
	t_env	*tmp;
	t_env	*new;
	char	*env_name;
	int		unset_flag;

	tmp = *env_list;
	unset_flag = 0;
	while (tmp->next != NULL)
	{
		env_name = tmp->next->name;
		if (ft_strcmp(env_name, name) == 0)
		{
			lstdelone_env_elem(tmp, tmp->next);
			break ;
		}
		tmp = tmp->next;
	}
	new = lstnew_env(ft_strdup(name), ft_strdup(val));
	new->unset_flag = 0;
	if (new != NULL)
		lstadd_back_env(env_list, new);
}

char	*get_name(t_env *env_list, char *name)
{
	t_env	*tmp_list;
	char	*tmp_name;

	tmp_list = env_list->next;
	while (tmp_list != NULL)
	{
		tmp_name = tmp_list->name;
		if (ft_strcmp(tmp_name, name) == 0)
			return (tmp_name);
		tmp_list = tmp_list->next;
	}
	return (NULL);
}

char	*get_value(t_env *env_list, char *name)
{
	t_env	*tmp_list;
	char	*tmp_name;

	tmp_list = env_list->next;
	while (tmp_list != NULL)
	{
		tmp_name = tmp_list->name;
		if (ft_strcmp(tmp_name, name) == 0)
			return (tmp_list->val);
		tmp_list = tmp_list->next;
	}
	return (NULL);
}

void	built_in_env(t_command **cmd, t_env *env_list)
{
	t_env	*tmp_list;

	if ((*cmd)->word[1] == NULL)
	{
		tmp_list = env_list;
		while (tmp_list != NULL)
		{
			if (tmp_list->name != NULL && tmp_list->val != NULL)
			{
				ft_putstr_fd(tmp_list->name, 1);
				ft_putchar_fd('=', 1);
				ft_putstr_fd(tmp_list->val, 1);
				ft_putchar_fd('\n', 1);
			}
			tmp_list = tmp_list->next;
		}
		g_exit_status = 0;
	}
	else
	{
		env_error_msg((*cmd)->word[1]);
		g_exit_status = 127;
	}
}

void	env_error_msg(char *err_word)
{
	ft_putstr_fd("env: ", 2);
	ft_putstr_fd(err_word, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}
