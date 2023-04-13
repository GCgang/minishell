/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:59:21 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/13 13:25:50 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

pid_t	execute_binary(t_command **process, t_env **env_list,
						int cmd_cnt, char **envp)
{
	pid_t		pid;

	if (pipe((*process)->pipe_fd) == -1)
	{
		clear_all(NULL, env_list, process);
		exit_error_ctl("Error : pipe(execute_binary)");
	}
	pid = fork();
	if (pid == -1)
	{
		clear_all(NULL, env_list, process);
		exit_error_ctl("Error : fork(execute_binary)");
	}
	else if (pid == 0)
	{
		exec_signal(1);
		child_process(process, env_list, cmd_cnt, envp);
	}
	else if (pid > 0)
	{
		exec_signal(0);
		parent_process(process);
	}
	return (pid);
}

void	parent_process(t_command **process)
{
	if ((*process)->backup_fd != 0)
	{
		close((*process)->backup_fd);
	}
	if ((*process)->pipe)
		(*process)->next->backup_fd = dup((*process)->pipe_fd[0]);
	close((*process)->pipe_fd[0]);
	close((*process)->pipe_fd[1]);
}

void	child_process(t_command **process, t_env **env_list,
						int cmd_cnt, char **envp)
{
	if ((*process)->std_in != 0)
		child_stdin_dup2((*process)->std_in, STDIN_FILENO);
	else if (cmd_cnt > 0)
		child_stdin_dup2((*process)->backup_fd, STDIN_FILENO);
	if ((*process)->std_out != 1)
		child_stdout_dup2((*process)->std_out, STDOUT_FILENO);
	else if ((*process)->pipe)
		dup2((*process)->pipe_fd[1], STDOUT_FILENO);
	close((*process)->pipe_fd[0]);
	close((*process)->pipe_fd[1]);
	if ((*process)->word != NULL && (*process)->word[0] != NULL)
	{
		if (is_built_in(*process))
			execute_built_in(process, env_list, cmd_cnt);
		else
		{
			if ((*process)->std_in != -1)
				run_execve(*process, env_list, envp);
		}
	}
	exit(g_exit_status);
}

void	exec(t_command **cmd, t_env **env_list, char **envp)
{
	t_command	*process;
	int			cmd_cnt;
	pid_t		pid;

	process = (*cmd);
	cmd_cnt = 0;
	while (process != NULL)
	{
		if (check_here_document(process) == -1 || redirection(&process) == -1)
			return ;
		if (is_built_in(process) && cmd_cnt == 0 && process->pipe == 0
			&& process->word != NULL && process->word[0] != NULL)
		{
			only_built_in(cmd, env_list, cmd_cnt);
			return ;
		}
		else
			pid = execute_binary(&process, env_list, cmd_cnt, envp);
		process = process->next;
		cmd_cnt++;
	}
	wait_process(cmd_cnt, pid);
	unlink_file(*cmd);
}

void	wait_process(int cmd_cnt, pid_t pid)
{
	int	status;

	while (cmd_cnt--)
	{
		if (pid == waitpid(-1, &status, 0))
		{
			if (WIFEXITED(status))
			{
				g_exit_status = WEXITSTATUS(status);
			}
			else if (WIFSIGNALED(status))
			{
				g_exit_status = (128 + WTERMSIG(status));
			}
			if (WTERMSIG(status) == SIGINT)
				printf("\n");
			else if (WTERMSIG(status) == SIGQUIT)
				printf("Quit: 3\n");
		}
	}
	init_signal();
}
