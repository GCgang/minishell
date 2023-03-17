/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:26:56 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/17 19:16:45 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	built_in_env(char **envp)
{
	int	i;

	i = -1;
	// check unset PATH case
	// if (access(PATH, F_OK) == -1)
	// {
	// 	perror("command not found");
	// 	//exit_status = 127;
	// }
	while (envp[++i])
	{
		ft_putstr_fd(envp[i], 1);
		ft_putchar_fd('\n', 1);
	}
	//exit_status = 0;
	return ;
}
