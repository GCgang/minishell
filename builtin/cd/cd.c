/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <jun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:26:49 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/22 00:15:22 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

void	update_pwd(t_env *env_list)
{
	char	*pwd;

	if (get_name(env_list, "PWD") != NULL)
	{
		//init_envp(env_list, "OLDPWD", get_val(env_list, "PWD"))
	}
	pwd = getcwd(NULL, PATH_MAX);
	//init_envp(env_list, "PWD", get_val(env_list, "PWD"));
	free(pwd);
}

// void	init_envp(t_env *env_list, char *name, char *val)
// {
// 	t_env	*tmp_list;
// 	char	*tmp_name;

// 	tmp_list = env_list->next;
// 	while (tmp_list != NULL)
// 	{
// 		tmp_name = tmp_list->name;
// 		if (ft_strcmp(tmp_name, name) == 0)
// 		{
// 		}
// 		tmp_list = tmp_list->next;
// 	}
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

void	change_home_dir(t_env *env_list)
{
	if (get_name(env_list, "HOME") == NULL)
	{
		ft_putstr_fd("Minishell: cd: HOME not set\n", 2);
		env_list->status = 1;
		return ;
	}
	else if (chdir(get_name(env_list, "HOME")) == -1)
	{
		ft_putstr_fd("Minishell: cd: No such file or directory\n", 2);
		env_list->status = 1;
		return ;
	}
	//update_pwd();
	env_list->status = 0;
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
	env_list->status = 0;
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
	else if (chdir(get_name(env_list, "OLDPWD")) == -1)
	{
		ft_putstr_fd("Minishell: cd: No such file or directory\n", 2);
		env_list->status = 1;
		return ;
	}
	//update_pwd();
	env_list->status = 0;
}

void	built_in_cd(t_command **cmd, t_env *env_list)
{
	char	*cmd;

	if ((*cmd)->word[1] == NULL) // || ft_strcmp((*cmd)->word[1], "~") == 0
		change_home_dir(env_list);
	// else if ((*cmd)->word[1][0] == '$')
	// 	change_env_dir(;
	else if ((*cmd)->word[1] == '-')
		change_oldpwd_dir(env_list);
	else
		change_new_dir(env_list, (*cmd)->word[1]);
}
