/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:59:21 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/26 21:58:03 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

void	execute_built_in(t_command **cmd, t_env **env_list, pid_t pid)
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
// void	leaks(void)
// {
// 	system("leaks minishell");
// }

// void	execute_bin(t_command **cmd, t_env	**env_list);
// void	child_process();
// void	parent_process();
// void	execute(t_command **cmd, t_env **env_list)
// {
// 	int		idx;
// 	int		*pipe_fd;
// 	pid_t	pid;

// 	idx = -1;
// 	while (++idx < pipe_cnt)
// 	{
// 		if (pipe(pipe_fd) == -1)
// 			exit(1); //error
// 		pid = fork();
// 		if (pid == -1)
// 			exit(1); //error
// 		else if (pid == 0)
// 			child_process();
// 		else
// 			parent_process();
// 	}
// 	while (idx--)
// 		waitpid(-1, NULL, 0);
// }

void	exec(t_command **cmd, t_env **env_list, pid_t pid)
{
	int	pipeline;
	int	builtin;

	pipeline = 0;
	builtin = 1;
	if (pipeline == 0)
	{
		if (builtin)
			execute_built_in(cmd, env_list, 1);
		// else
		// 	execute_bin(cmd, env_list);
	}
	// else
	// 	execute(cmd, env_list);
	(void)pid;
}
