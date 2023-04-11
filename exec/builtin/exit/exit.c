/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:26:58 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/11 15:31:49 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

int	check_exit_syntax(char *exit_val)
{
	int	i;
	int	sign_cnt;

	i = -1;
	sign_cnt = 0;
	while (exit_val != 0 && exit_val[++i])
	{
		if (exit_val[i] == '+' || exit_val[i] == '-')
		{
			sign_cnt++;
			i++;
		}
		if (ft_isdigit(exit_val[i]) == 0)
			return (0);
		if (sign_cnt > 2)
			return (0);
	}
	return (1);
}

void	built_in_exit(t_command **cmd, t_env **env_list, int cmd_cnt)
{
	if (cmd_cnt == 0)
		ft_putstr_fd("exit\n", 1);
	if (check_exit_syntax((*cmd)->word[1]) == 0)
		g_exit_status = print_exit_numeric_error((*cmd)->word[1]);
	else if ((*cmd)->word[1] != NULL && (*cmd)->word[2] != NULL)
	{
		ft_putstr_fd("Minishell: exit: too many arguments\n", 2);
		g_exit_status = 1;
		return ;
	}
	else if ((*cmd)->word[1] == NULL)
		g_exit_status = 0;
	else
		g_exit_status = ft_atol((*cmd)->word[1]);
	clear_all(NULL, env_list, cmd);
	exit (g_exit_status);
}

long long	ft_atol(char *str)
{
	long long	result;
	long long	before;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (ft_strcmp(&str[i], "-9223372036854775808") == 0)
		return (0);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (ft_isdigit(str[i]) != 0)
	{
		before = result;
		result = result * 10 + (str[i++] - '0');
		if (before > result)
			return (print_exit_numeric_error(str));
	}
	return (result * sign);
}

int	print_exit_numeric_error(char *err_str)
{
	ft_putstr_fd("Minishell: exit: ", 2);
	ft_putstr_fd(err_str, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	return (2);
}

void	exit_error_ctl(char *err_msg)
{
	ft_putstr_fd(err_msg, 2);
	exit (1);
}
