/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <jun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:26:49 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/11 01:09:24 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

void	update_pwd(t_env **env_list, char *old_pwd)
{
	char	*pwd;

	if (get_name(*env_list, "PWD") != NULL)
	{
		pwd = getcwd(NULL, PATH_MAX);
		init_envp(env_list, "PWD", pwd);
		free(pwd);
	}
	init_envp(env_list, "OLDPWD", old_pwd);
	g_exit_status = 0;
}

void	change_home_dir(t_env **env_list)
{
	char	*old_pwd;

	if (get_value(*env_list, "PWD") != NULL)
		old_pwd = (ft_strdup(get_value(*env_list, "PWD")));
	else
		old_pwd = NULL;
	if (get_name(*env_list, "HOME") == NULL)
	{
		ft_putstr_fd("Minishell: cd: HOME not set\n", 2);
		g_exit_status = 1;
		return (free(old_pwd));
	}
	else if (chdir(get_value(*env_list, "HOME")) == -1)
	{
		ft_putstr_fd("Minishell: cd: No such file or directory\n", 2);
		g_exit_status = 1;
		return (free(old_pwd));
	}
	update_pwd(env_list, old_pwd);
	free(old_pwd);
}

void	change_new_dir(t_env **env_list, char *name)
{
	char	*old_pwd;

	if (get_value(*env_list, "PWD") != NULL)
		old_pwd = (ft_strdup(get_value(*env_list, "PWD")));
	else
		old_pwd = NULL;
	if (chdir(name) == -1)
	{
		ft_putstr_fd("Minishell: cd: No such file or directory\n", 2);
		g_exit_status = 1;
		return (free(old_pwd));
	}
	update_pwd(env_list, old_pwd);
	free(old_pwd);
}

void	change_oldpwd_dir(t_env **env_list)
{
	char	*old_pwd;

	if (get_value(*env_list, "PWD") != NULL)
		old_pwd = (ft_strdup(get_value(*env_list, "PWD")));
	else
		old_pwd = NULL;
	if (get_value(*env_list, "OLDPWD") == NULL)
	{
		ft_putstr_fd("Minishell: cd: OLDPWD not set\n", 2);
		g_exit_status = 1;
		return (free(old_pwd));
	}
	else if (chdir(get_value(*env_list, "OLDPWD")) == -1)
	{
		ft_putstr_fd("Minishell: cd: No such file or directory\n", 2);
		g_exit_status = 1;
		return (free(old_pwd));
	}
	else
	{
		ft_putstr_fd(get_value(*env_list, "OLDPWD"), 1);//
		ft_putchar_fd('\n', 1);
	}
	update_pwd(env_list, old_pwd);
	free(old_pwd);
}

void	built_in_cd(t_command **cmd, t_env **env_list)
{
	if ((*cmd)->word[1] == NULL)
		change_home_dir(env_list);
	else if ((*cmd)->word[2] != NULL)
	{
		ft_putstr_fd("Minishell: cd: too many arguments\n", 2);
		g_exit_status = 1;
	}
	else if (ft_strcmp((*cmd)->word[1], "-") == 0)
		change_oldpwd_dir(env_list);
	else
		change_new_dir(env_list, (*cmd)->word[1]);
}
