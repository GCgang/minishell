/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:26:52 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/07 17:59:43 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "echo.h"

int	check_echo_option(char *cmd, int *option_n)
{
	int	i;

	i = 0;
	if (cmd[i] != '-')
	{
		return (0);
	}
	while (cmd[++i] == 'n')
		;
	if (cmd[i] == '\0')
	{
		*option_n = 1;
		return (1);
	}
	return (0);
}

void	built_in_echo(t_command **cmd)
{
	int		idx;
	int		option_n;

	idx = 0;
	option_n = 0;
	if ((*cmd)->word[1] == NULL || (*cmd)->word[1][0] == '\0')
		ft_putchar_fd('\n', 1);
	else
	{
		while ((*cmd)->word[++idx] != NULL)
			if (check_echo_option((*cmd)->word[idx], &option_n) == 0)
				break ;
		while ((*cmd)->word[idx] != NULL)
		{
			ft_putstr_fd((*cmd)->word[idx], 1);
			if ((*cmd)->word[idx + 1] != NULL)
				ft_putchar_fd(' ', 1);
			idx++;
		}
		if (option_n == 0)
			ft_putchar_fd('\n', 1);
	}
	g_exit_status = 0;
}
