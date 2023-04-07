/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:26:49 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/07 17:59:37 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

void	update_pwd(t_env **env_list, char *old_pwd)
{
	char	*pwd;

	pwd = getcwd(NULL, PATH_MAX);
	if (get_name(*env_list, "OLDPWD") != NULL)
		init_envp(env_list, "OLDPWD", old_pwd);
	if (get_name(*env_list, "PWD") != NULL)
		init_envp(env_list, "PWD", pwd);
	free(pwd);
	g_exit_status = 0;
}

void	change_home_dir(t_env **env_list)
{
	char	*old_pwd;

	old_pwd = getcwd(NULL, PATH_MAX);
	if (get_name(*env_list, "HOME") == NULL)
	{
		ft_putstr_fd("Minishell: cd: HOME not set\n", 2);
		g_exit_status = 1;
		return ;
	}
	else if (chdir(get_value(*env_list, "HOME")) == -1)
	{
		ft_putstr_fd("Minishell: cd: No such file or directory\n", 2);
		g_exit_status = 1;
		return ;
	}
	update_pwd(env_list, old_pwd);
	free(old_pwd);
}

void	change_new_dir(t_env **env_list, char *name)
{
	char	*old_pwd;

	old_pwd = getcwd(NULL, PATH_MAX);
	if (chdir(name) == -1)
	{
		ft_putstr_fd("Minishell: cd: No such file or directory\n", 2);
		g_exit_status = 1;
		return ;
	}
	update_pwd(env_list, old_pwd);
	free(old_pwd);
}

void	change_oldpwd_dir(t_env **env_list)
{
	char	*old_pwd;

	old_pwd = getcwd(NULL, PATH_MAX);
	if (get_value(*env_list, "OLDPWD") == NULL)
	{
		ft_putstr_fd("Minishell: cd: OLDPWD not set\n", 2);
		g_exit_status = 1;
		return ;
	}
	else if (chdir(get_value(*env_list, "OLDPWD")) == -1)
	{
		ft_putstr_fd("Minishell: cd: No such file or directory\n", 2);
		g_exit_status = 1;
		return ;
	}
	update_pwd(env_list, old_pwd);
	free(old_pwd);
}

void	built_in_cd(t_command **cmd, t_env **env_list)
{
	if ((*cmd)->word[1] == NULL)
		change_home_dir(env_list);
	else if (ft_strcmp((*cmd)->word[1], "-") == 0)
		change_oldpwd_dir(env_list);
	else
		change_new_dir(env_list, (*cmd)->word[1]);
}
