/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:26:49 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/21 15:41:35 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

void	update_pwd(t_env *env_list)
{
	// char	*new_pwd;
	// char	*new_old_pwd;

	// new_pwd = getcwd(NULL, PATH_MAX);
	// new_old_pwd = ft_strdup(get_name(env_list, "OLDPWD"));
	// update pwd

	/*
	char	*oldpwd;
	char	*pwd;

	if (!find_envp(head, "OLDPWD"))
		insert_envp(&head, "OLDPWD", NULL);
	oldpwd = find_envp_value(head, "PWD");
	if (!oldpwd)
		update_envp(head, "OLDPWD", NULL);
	else
		update_envp(head, "OLDPWD", oldpwd);
	if (find_envp(head, "PWD"))
	{
		pwd = getcwd(NULL, 0);
		if (!pwd)
			return (1);
		update_envp(head, "PWD", pwd);
		free(pwd);
	}
	return (0);
	*/

	/*
	to_put = ft_join_and_free(ft_strdup("OLDPWD="), \
								get_value_by_key(g_global->g_envl, "PWD"));
	add_set_env_to_list(g_global->g_envl, to_put);
	free(to_put);
	to_put = ft_join_and_free(ft_strdup("PWD="), getcwd(NULL, 1024));
	add_set_env_to_list(g_global->g_envl, to_put);
	free(to_put);
	*/
	char	*pwd_val;
	char	*old_pwd_val;

	if (get_name(env_list, "OLDPWD") == NULL)
	{
		//init_old_pwd_name()
		//init_old_pwd_val() -> get pwd val
	}
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
	else if (chdir(get_name(env_list, "OLDPWD")) == -1)
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
	if ((*cmd)->word[1] == NULL) // || ft_strcmp((*cmd)->word[1], "~") == 0
		change_home_dir(env_list);
	// else if ((*cmd)->word[1][0] == '$')
	// 	change_env_dir(;
	else if ((*cmd)->word[1] == '-')
		change_oldpwd_dir(env_list);
	else
		change_new_dir(env_list, (*cmd)->word[1]);
}
