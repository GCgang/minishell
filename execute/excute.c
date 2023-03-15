/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:59:21 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/15 21:37:46 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excute.h"

void	excute_simple_built_in(char **argv)
{
	if (ft_strncmp(argv[1], "cd", 3) == 0)
		built_in_cd();
	else if (ft_strncmp(argv[1], "echo", 5) == 0)
		built_in_echo();
	else if (ft_strncmp(argv[1], "env", 4) == 0)
		built_in_env();
	else if (ft_strncmp(argv[1], "exit", 5) == 0)
		built_in_exit();
	else if (ft_strncmp(argv[1], "export", 7) == 0)
		built_in_export();
	else if (ft_strncmp(argv[1], "pwd", 4) == 0)
		built_in_pwd();
	else if (ft_strncmp(argv[1], "unset", 5) == 0)
		built_in_unset();
}

int	main(int argc, char **argv, char **envp)
{
	int	pipeline;

	pipeline = 0;
	if (pipeline == 0)
		excute_simple_built_in(argv);
	else
	{
		//excute
	}
}
