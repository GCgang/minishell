/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:26:58 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/22 21:06:49 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

int	check_exit_syntax(char *exit_val)
{
	int	i;

	i = -1;
	while (exit_val[++i])
	{
		if (ft_isdigit(exit_val[i]) == 0)
			return (0);
	}
	return (1);
}

void	built_in_exit(t_command **cmd, t_env *env_list)
{
	if ((*cmd)->word[1] != NULL && (*cmd)->word[2] != NULL)
	{
		ft_putstr_fd("Minishell: exit: too many arguments\n", 2);
		env_list->status = 255;
		return ;
	}
	else if (check_exit_syntax((*cmd)->word[1]) == 0)
	{
		ft_putstr_fd("Minishell: exit: numeric argument required\n", 2);
		env_list->status = 255;
		return ;
	}
	else if ((*cmd)->word[1] == NULL)
	{
		ft_putstr_fd("exit\n", 2);
		env_list->status = 0;
	}
	else
	{
		ft_putstr_fd("exit\n", 2);
		env_list->status = ft_atoi((*cmd)->word[1]);
	}
	exit (env_list->status);
}
