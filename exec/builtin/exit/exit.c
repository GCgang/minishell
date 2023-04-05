/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:26:58 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/05 11:47:36 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

int	check_exit_syntax(char *exit_val)
{
	int	i;

	i = -1;
	while (exit_val != 0 && exit_val[++i])
	{
		if (ft_isdigit(exit_val[i]) == 0)
			return (0);
	}
	return (1);
}

void	built_in_exit(t_command **cmd)
{
	if (check_exit_syntax((*cmd)->word[1]) == 0)
	{
		ft_putstr_fd("Minishell: exit: numeric argument required\n", 2);
		g_exit_status = 255;
	}
	else if ((*cmd)->word[1] != NULL && (*cmd)->word[2] != NULL)
	{
		ft_putstr_fd("Minishell: exit: too many arguments\n", 2);
		g_exit_status = 255;
		return ;
	}
	else if ((*cmd)->word[1] == NULL)
	{
		ft_putstr_fd("exit\n", 2);
		g_exit_status = 0;
	}
	else
	{
		ft_putstr_fd("exit\n", 2);
		g_exit_status = ft_atol((*cmd)->word[1]);
	}
	exit (g_exit_status);
}

long long	ft_atol(const char *str)
{
	long long	result;
	long long	before;
	int			sign;

	result = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str) != 0)
	{
		before = result;
		result = result * 10 + (*str - '0');
		if (before > result)
		{
			ft_putstr_fd("Minishell: exit: numeric argument required\n", 2);
			return (255);
		}
		str++;
	}
	return (result * sign);
}
