/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:59:21 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/31 21:44:39 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

int	is_built_in(char *word)
{
	if (word != NULL)
	{
		if (ft_strcmp(word, "cd") == 0)
			return (1);
		else if (ft_strcmp(word, "echo") == 0)
			return (1);
		else if (ft_strcmp(word, "env") == 0)
			return (1);
		else if (ft_strcmp(word, "exit") == 0)
			return (1);
		else if (ft_strcmp(word, "export") == 0)
			return (1);
		else if (ft_strcmp(word, "pwd") == 0)
			return (1);
		else if (ft_strcmp(word, "unset") == 0)
			return (1);
	}
	return (0);
}

void	execute_built_in(t_command **cmd, t_env **env_list, int pipe)
{
	if (ft_strcmp((*cmd)->word[0], "cd") == 0)
		built_in_cd(cmd, env_list);
	else if (ft_strcmp((*cmd)->word[0], "echo") == 0)
		built_in_echo(cmd);
	else if (ft_strcmp((*cmd)->word[0], "env") == 0)
		built_in_env(cmd, *env_list);
	else if (ft_strcmp((*cmd)->word[0], "exit") == 0)
		built_in_exit(cmd);
	else if (ft_strcmp((*cmd)->word[0], "export") == 0)
		built_in_export(cmd, env_list);
	else if (ft_strcmp((*cmd)->word[0], "pwd") == 0)
		built_in_pwd(cmd);
	else if (ft_strcmp((*cmd)->word[0], "unset") == 0)
		built_in_unset(cmd, *env_list);
	if (pipe == 0)
		return ;
	else if (pipe == 1)
		exit((*env_list)->status);
}

// void	leaks(void)
// {
// 	system("leaks minishell");
// }

char	*check_cmd(t_command *process, t_env **env_list)
{
	int		i;
	char	*cmd;
	char	*temp;

	if (get_name(*env_list, "PATH") == NULL)
		return (NULL);
	i = -1;
	temp = ft_strjoin("/", process->word[0]);
	if (access(temp, X_OK) == 0)
		return (temp);
	while (process->path[++i] != NULL)
	{
		cmd = ft_strjoin(process->path[i], temp);
		if (access(cmd, X_OK) == 0)
			return (cmd);
		free(cmd);
	}
	free(temp);
	return (NULL);
}

void	run_execve(t_command *process, t_env **env_list)
{
	char	*path_cmd;

	path_cmd = check_cmd(process, env_list);
	if (path_cmd == NULL)
	{
		ft_putstr_fd("Minishell: ", 2);
		ft_putstr_fd(process->word[0], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		exit(127);
	}
	if (execve(path_cmd, process->word, NULL) == -1)
	{
		ft_putstr_fd("Minishell: ", 2);
		ft_putstr_fd(process->word[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
}

void	child_process(t_command **process, t_env **env_list, int cmd_cnt)
{
	if (is_built_in((*process)->word[0]))
		execute_built_in(process, env_list, (*process)->pipe);
	else
		run_execve(*process, env_list);
}

void	parent_process(t_command **process, int cmd_cnt)
{
}

void	execute_binary(t_command **process, t_env **env_list, int cmd_cnt)
{
	pid_t		pid;

	if (cmd_cnt % 2 == 0)
		if (pipe((*process)->even_fd) == -1)
			exit(1);
	if (cmd_cnt % 2 == 1)
		if (pipe((*process)->odd_fd) == -1)
			exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	else if (pid == 0)
		child_process(process, env_list, cmd_cnt);
	else if (pid > 0)
		parent_process(process, cmd_cnt);
}

int	redirection(t_command **cmd)
{
	t_command	*process;
	int			idx;

	process = (*cmd);
	idx = -1;
	if (process->redir == NULL || process->redir_val == NULL)
		return (1);
	while (process->redir[++idx] != NULL)
	{
		if (ft_strcmp(process->redir[idx], "<") == 0)
		{
			process->std_in = i_redirection(cmd, idx);
			if (process->std_in == 0)
				return (0);
		}
		else if (ft_strcmp(process->redir[idx], ">") == 0)
			process->std_out = o_trunc_redirection(cmd, idx);
		else if (ft_strcmp(process->redir[idx], ">>") == 0)
			process->std_out = o_append_redirection(cmd, idx);
		// else	// heredoc ?
		// return ;
	}
	return (1);
}

int	i_redirection(t_command **cmd, int idx)
{
	int	infile_fd;

	infile_fd = open((*cmd)->redir_val[idx], O_RDONLY);
	if (infile_fd == -1)
	{
		ft_putstr_fd("Minishell: ", 2);
		ft_putstr_fd((*cmd)->redir_val[idx], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		g_exit_status = 1;
		return (0);
	}
	g_exit_status = 0;
	return (infile_fd);
}

int	o_trunc_redirection(t_command **cmd, int idx)
{
	int	outfile_fd;

	outfile_fd = open((*cmd)->redir_val[idx], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd == -1)
	{
		ft_putstr_fd("Minishell: ", 2);
		ft_putstr_fd((*cmd)->redir_val[idx], 2);
		perror("\n");
		g_exit_status = 1;
		return (1);
	}
	g_exit_status = 0;
	return (outfile_fd);
}

int	o_append_redirection(t_command **cmd, int idx)
{
	int	outfile_fd;

	outfile_fd = open((*cmd)->redir_val[idx], O_RDWR | O_CREAT | O_APPEND, 0644);
	if (outfile_fd == -1)
	{
		ft_putstr_fd("Minishell: ", 2);
		ft_putstr_fd((*cmd)->redir_val[idx], 2);
		perror("\n");
		g_exit_status = 1;
		return (1);
	}
	g_exit_status = 0;
	return (outfile_fd);
}

void	exec(t_command **cmd, t_env **env_list)
{
	t_command	*process;
	int			cmd_cnt;

	process = (*cmd);
	cmd_cnt = 0;
	while (process != NULL)
	{
		if (redirection(&process) == 0 && process->pipe == 0)
			break ;
		if (process->word != NULL && process->word[0] != NULL)
		{
			if (is_built_in(process->word[0]) && process->pipe == 0 && cmd_cnt == 0)
				execute_built_in(&process, env_list, process->pipe);
			else
				execute_binary(&process, env_list, cmd_cnt);
			cmd_cnt++;
		}
		process = process->next;
	}
	while (cmd_cnt--)
		waitpid(-1, NULL, 0);
}
