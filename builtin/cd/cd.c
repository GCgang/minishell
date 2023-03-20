/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <jun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:26:49 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/21 01:13:38 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

// void	update_pwd(t_env *env_list)
// {
// 	char	*new_pwd;
// 	char	*new_old_pwd;

// 	new_pwd = getcwd(NULL, PATH_MAX);
// 	new_old_pwd = ft_strdup(get_name(env_list, "OLDPWD"));
// }

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

void	change_home_dir(t_env *env_list)
{
	if (get_name(env_list, "HOME") == NULL)
	{
		ft_putstr_fd("Minishell: cd: HOME not set\n", 2);
		env_list->status = 1;
		return ;
	}
	if (chdir(get_name(env_list, "HOME")) == -1)
	{
		ft_putstr_fd("Minishell: cd: No such file or directory\n", 2);
		env_list->status = 1;
		return ;
	}
	//update_pwd();
}

void	change_new_dir(t_env *env_list, char *name)
{
	if (chdir(name) == -1)
	{
		ft_putstr_fd("Minishell: cd: No such file or directory\n", 2);
		env_list->status = 1;
		return ;
	}
	//update_pwd();
}

// void	change_env_dir(t_env *env_list)
// {
// 	if (chdir(dir) == -1)
// 		chdir(getenv("HOME"));
// 	//update_envp();
// }

void	change_oldpwd_dir(t_env *env_list)
{
	if (get_name(env_list, "OLDPWD") == NULL)
	{
		ft_putstr_fd("Minishell: cd: OLDPWD not set\n", 2);
		env_list->status = 1;
		return ;
	}
	if (chdir(get_name(env_list, "OLDPWD")) == -1)
	{
		ft_putstr_fd("Minishell: cd: No such file or directory\n", 2);
		env_list->status = 1;
		return ;
	}
	//update_pwd();

}

void	built_in_cd(t_command **cmd, t_env *env_list)
{
	char	*cmd;

	//cd or cd ~
	if ((*cmd)->word[1] == NULL || ft_strcmp((*cmd)->word[1], "~") == 0)
		change_home_dir(env_list);
	// else if ((*cmd)->word[1][0] == '$')
	// 	change_env_dir(;
	else if ((*cmd)->word[1] == '-')
		change_oldpwd_dir(env_list);
	else
		change_new_dir(env_list, (*cmd)->word[1]);
}
