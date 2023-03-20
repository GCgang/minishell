/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:26:49 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/19 17:08:15 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

void	change_home_dir(char *dir)
{
	if (getenv("HOME") == NULL)
	{
		ft_putstr_fd("HOME not set", 2);
		//g_exit_status = 1;
		return ;
	}
	if (chdir(getenv("HOME")) == -1)
	{
		ft_putstr_fd("No such file or directory", 2);
		//g_exit_status = 1;
		return ;
	}
	//update_envp();
}

void	change_new_dir(char *dir)
{
	if (chdir(dir) == -1)
	{
		ft_putstr_fd("No such file or directory", 2);
		//g_exit_status = 1;
		return ;
	}
	//update_envp();
}

void	change_env_dir(char *dir)
{
	if (chdir(dir) == -1)
		chdir(getenv("HOME"));
	//update_envp();
}

void	change_oldpwd_dir(char *dir)
{
	if (getenv("OLDPWD") == NULL)
	{
		ft_putstr_fd("OLDPWD not set", 2);
		//g_exit_status = 1;
		return ;
	}
	if (chdir(dir) == -1)
	{
		ft_putstr_fd("No such file or directory", 2);
		//g_exit_status = 1;
		return ;
	}
	//update_envp();

}

void	built_in_cd(void)
{
	char	*dir;
	char	*cmd;

	//cd or cd ~
	if (dir == NULL || ft_strcmp(dir, "~") == 0)
		change_home_dir(dir);
	else if (dir[0] == '$')
		change_env_dir(dir);
	else if (dir[0] == '-')
		change_oldpwd_dir(dir);
	else
		change_new_dir(dir);
	return ;
}
