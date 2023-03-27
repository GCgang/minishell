/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <jun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:59:21 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/27 21:16:50 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

void	execute_built_in(t_command **cmd, t_env **env_list, pid_t pid)
{
	if ((*cmd)->word[0] != NULL)
	{
		if (ft_strcmp((*cmd)->word[0], "cd") == 0)
			built_in_cd(cmd, env_list);
		else if (ft_strcmp((*cmd)->word[0], "echo") == 0)
			built_in_echo(cmd, *env_list);
		else if (ft_strcmp((*cmd)->word[0], "env") == 0)
			built_in_env(cmd, *env_list);
		else if (ft_strcmp((*cmd)->word[0], "exit") == 0)
			built_in_exit(cmd, *env_list);
		else if (ft_strcmp((*cmd)->word[0], "export") == 0)
			built_in_export(cmd, env_list);
		else if (ft_strcmp((*cmd)->word[0], "pwd") == 0)
			built_in_pwd(*env_list);
		else if (ft_strcmp((*cmd)->word[0], "unset") == 0)
			built_in_unset(cmd, *env_list);
		(void)pid;
	}
}
// void	leaks(void)
// {
// 	system("leaks minishell");
// }

// void	execute_bin(t_command **cmd, t_env	**env_list);
void	redirection()
{
	// if ('<')
	// 	// next file ?
	// else
	// 	// error
	// if ('>')
	// 	// next file ?
	// else
	// 	// make file
}

void	child_process()
{
	// close(pipe_fd[0]);
	// dup2(pipe_fd[1], 1);
	// close(pipe_fd[1]);
	// redirection();
	// execute_built_in();
	// execute_binary();
	// exit();
}
void	parent_process()
{
	// close(pipe_fd[1]);
	// dup2(pipe_fd[0], 0);
	// close(pipe_fd[0]);
}

void	execute_pipeline(t_command **cmd, t_env **env_list)
{
	t_command	*process;
	pid_t		pid;
	int			*pipe_fd;
	int			idx;

	process = *cmd;
	idx = 0;
	whlie (process != NULL)
	{
		if (pipe(pipe_fd) == -1)
			exit(1); // error
		pid = fork();
		if (pid == -1)
			exit(1); // error
		else if (pid == 0)
			child_process();
		else
			parent_process();
		process = process->next;
		idx++;
	}
	while (idx--)
		waitpid(-1, NULL, 0);
}

void	exec(t_command **cmd, t_env **env_list, pid_t pid)
{
	int			pipeline;

	
	pipeline = 0;
	if (pipeline == 0 && (*cmd) != NULL)
	{
		//redirection();
		execute_built_in(cmd, env_list, 1);
		//execute_binary();
	}
	else
	{
		execute_pipeline(cmd, env_list);
	}
	(void)pid;
}
