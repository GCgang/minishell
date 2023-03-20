/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:26:52 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/20 16:53:45 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "echo.h"

void	check_echo_option(char **cmd, int *option_n)
{
	int	i;

	i = 0;
	if (cmd[0][i] != '-')
		return ;
	while (cmd[0][++i] == 'n')
		(*option_n)++;
	if (cmd[0][i] != ' ')
	{
		*option_n = 0;
		return ;
	}
	if (cmd[0][i] == ' ' && *option_n > 0)
	{
		while (**cmd != ' ')
			(*cmd)++;
		*option_n = 1;
		return ;
	}
}

void	built_in_echo(t_command **cmd, t_env *env_list)
{
	int		i;
	int		option_n;

	i = -1;
	option_n = 0;
	if ((*cmd)->word[1] == NULL || (*cmd)->word[1][0] == '\0')
		ft_putchar_fd('\n', 1);
	else
	{
		check_echo_option((*cmd)->word[1], &option_n);
		ft_putstr_fd((*cmd)->word[1], 1);
		if (option_n == 0)
			ft_putchar_fd('\n', 1);
	}
	env_list->status = 0;
	return ;
}
