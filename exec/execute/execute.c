/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:59:21 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/04 21:39:14 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

void	execute_binary(t_command **process, t_env **env_list,
						int cmd_cnt, char **envp)
{
	pid_t		pid;

	if (pipe((*process)->pipe_fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	else if (pid == 0)
		child_process(process, env_list, cmd_cnt, envp);
	else if (pid > 0)
		parent_process(process);
}

void	parent_process(t_command **process)
{
	if ((*process)->pipe)
	{
		(*process)->next->backup_fd = dup((*process)->pipe_fd[0]);
	}
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
	if (is_built_in((*process)->word[0]))
	{
		execute_built_in(process, env_list);
		exit(g_exit_status);
	}
	else
	{
		run_execve(*process, env_list, envp);
		exit(g_exit_status);
	}
}

void	exec(t_command **cmd, t_env **env_list, char **envp)
{
	t_command	*process;
	int			cmd_cnt;

	process = (*cmd);
	cmd_cnt = 0;
	while (process != NULL)
	{
		check_here_document(process);
		if (redirection(&process) == 0 && process->pipe == 0)
			break ;
		if (process->word != NULL && process->word[0] != NULL)
		{
			if (is_built_in(process->word[0])
				&& process->pipe == 0 && cmd_cnt == 0)
			{
				only_built_in(process, env_list);
			}
			else
				execute_binary(&process, env_list, cmd_cnt, envp);
			cmd_cnt++;
		}
		process = process->next;
	}
	wait_process(cmd_cnt);
}

void	wait_process(int cmd_cnt)
{
	int	status;

	status = 0;
	while (cmd_cnt--)
		waitpid(-1, &status, 0);
}
