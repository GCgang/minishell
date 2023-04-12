/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:54:02 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/12 21:49:31 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

char	*check_cmd(t_command *process, t_env **env_list)
{
	int		i;
	char	*cmd;
	char	*temp;

	if (access(process->word[0], X_OK) == 0)
		return (process->word[0]);
	if (get_value(*env_list, "PATH") == NULL
		|| ft_strchr(process->word[0], '/')
		|| ft_strcmp(process->word[0], "\0") == 0)
		return (NULL);
	temp = ft_strjoin("/", process->word[0]);
	if (temp == NULL)
		exit_error_ctl("Error : ft_strjoin(check_cmd)");
	i = -1;
	while (process->path[++i] != NULL)
	{
		cmd = ft_strjoin(process->path[i], temp);
		if (cmd == NULL)
			exit_error_ctl("Error : ft_strjoin(check_cmd)");
		if (access(cmd, X_OK) == 0)
			return (cmd);
		free(cmd);
	}
	free(temp);
	return (NULL);
}

void	run_execve(t_command *process, t_env **env_list, char **envp)
{
	char		*path_cmd;
	struct stat	file_info;

	path_cmd = check_cmd(process, env_list);
	stat(path_cmd, &file_info);
	if (execve(path_cmd, process->word, envp) == -1)
	{
		if (S_ISDIR(file_info.st_mode))
		{
			if (ft_strcmp(process->word[0], ".") == 0)
				execve_error(FILENAME_ARGUMENT_REQUIRED, process->word[0], 2);
			else if (ft_strcmp(process->word[0], "..") == 0)
				execve_error(COMMAND_NOT_FOUND, process->word[0], 127);
			else if (ft_strcmp(process->word[0], "./") == 0 \
					|| ft_strcmp(process->word[0], "../") == 0)
				execve_error(IS_A_DIRECTORY, process->word[0], 126);
			else if (ft_strchr(process->word[0], '.') == NULL)
				execve_error(IS_A_DIRECTORY, process->word[0], 126);
		}
		else if (ft_strchr(process->word[0], '/') != NULL
			|| get_value(*env_list, "PATH") == NULL)
			execve_error(NO_SUCH_FILE_OR_DIRECTORY, process->word[0], 127);
		else
			execve_error(COMMAND_NOT_FOUND, process->word[0], 127);
	}
}

void	execve_error(int err_flag, char *err_word, int exit_status)
{
	if (err_flag == FILENAME_ARGUMENT_REQUIRED)
	{
		ft_putstr_fd("Minishell: .: filename argument required\n", 2);
		ft_putstr_fd(".: usage: . filename [argument]\n", 2);
	}
	else if (err_flag == IS_A_DIRECTORY)
	{
		ft_putstr_fd("Minishell: ", 2);
		ft_putstr_fd(err_word, 2);
		ft_putstr_fd(": Is a directory\n", 2);
	}
	else if (err_flag == NO_SUCH_FILE_OR_DIRECTORY)
	{
		ft_putstr_fd("Minishell: ", 2);
		ft_putstr_fd(err_word, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	else if (err_flag == COMMAND_NOT_FOUND)
	{
		ft_putstr_fd("Minishell: ", 2);
		ft_putstr_fd(err_word, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	g_exit_status = exit_status;
}
