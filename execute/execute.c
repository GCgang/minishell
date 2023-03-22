/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:59:21 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/22 13:15:38 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute.h"
//gcc execute.c strcmp.c ft_putchar_fd.c ft_putstr_fd.c ft_strlen.c ../builtin/cd/cd.c ../builtin/echo/echo.c ../builtin/env/env.c ../builtin/exit/exit.c ../builtin/export/export.c ../builtin/pwd/pwd.c ../builtin/unset/unset.c
// void	execute_built_in(char **argv, char **envp)
// {
// 	if (ft_strcmp(argv[1], "cd") == 0)
// 		built_in_cd();
// 	else if (ft_strcmp(argv[1], "echo") == 0)
// 		built_in_echo(argv);
// 	else if (ft_strcmp(argv[1], "env") == 0)
// 		built_in_env(envp);
// 	else if (ft_strcmp(argv[1], "exit") == 0)
// 		built_in_exit();
// 	else if (ft_strcmp(argv[1], "export") == 0)
// 		built_in_export();
// 	else if (ft_strcmp(argv[1], "pwd") == 0)
// 		built_in_pwd();
// 	else if (ft_strcmp(argv[1], "unset") == 0)
// 		built_in_unset();
// }
void	execute_built_in(t_command **cmd, t_env **env_list, pid_t pid)
{
	if (ft_strcmp((*cmd)->word[0], "cd") == 0)
		built_in_cd(cmd, *env_list);
	else if (ft_strcmp((*cmd)->word[0], "echo") == 0)
		built_in_echo(cmd, *env_list);
	else if (ft_strcmp((*cmd)->word[0], "env") == 0)
		built_in_env(cmd, *env_list);
	else if (ft_strcmp((*cmd)->word[0], "exit") == 0)
		built_in_exit(cmd, *env_list);
	else if (ft_strcmp((*cmd)->word[0], "export") == 0)
		built_in_export(cmd, *env_list);
	else if (ft_strcmp((*cmd)->word[0], "pwd") == 0)
		built_in_pwd(*env_list);
	else if (ft_strcmp((*cmd)->word[0], "unset") == 0)
		built_in_unset(cmd, *env_list);
}
// void	leaks(void)
// {
// 	system("leaks a.out");
// }

int	main(int argc, char **argv, char **envp)
{
	t_env		*env_list;
	t_command	*cmd;
	pid_t		pid;
	//atexit(leaks);
	// int	pipeline;
	// pipeline = 0;
	// if (pipeline == 0)
	// 	execute_built_in(argv, envp);
	execute_built_in(&cmd, env_list, 1);
	// else
	// {
	// 	//pipe...
	// 	//fork...
	// 	//execute_pipe_built_in(...);
	// 	//execute_cmd(...);
	// }
}
