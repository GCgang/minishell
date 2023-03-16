/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:59:21 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/16 22:31:42 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute.h"

void	execute_simple_built_in(char **argv)
{
	if (ft_strcmp(argv[1], "cd") == 0)
		built_in_cd();
	else if (ft_strcmp(argv[1], "echo") == 0)
		built_in_echo();
	else if (ft_strcmp(argv[1], "env") == 0)
		built_in_env();
	else if (ft_strcmp(argv[1], "exit") == 0)
		built_in_exit();
	else if (ft_strcmp(argv[1], "export") == 0)
		built_in_export();
	else if (ft_strcmp(argv[1], "pwd") == 0)
		built_in_pwd();
	else if (ft_strcmp(argv[1], "unset") == 0)
		built_in_unset();
}

// void	leaks(void)
// {
// 	system("leaks a.out");
// }

int	main(int argc, char **argv, char **envp)
{
	//atexit(leaks);
	int	pipeline;

	pipeline = 0;
	if (pipeline == 0)
		execute_simple_built_in(argv);
	// else
	// {
	// 	//pipe...
	// 	//fork...
	// 	//execute_pipe_built_in(...);
	// 	//execute_cmd(...);
	// }
}
