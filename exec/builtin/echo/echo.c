/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:26:52 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/23 20:00:32 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "echo.h"

// -nnnn -nnnn
// void	check_echo_option(char **cmd, int *option_n, int *idx)
// {
// 	int	i;

// 	i = 0;
// 	if (cmd[1][i] != '-')
// 		return ;
// 	while (cmd[1][++i] == 'n')
// 		(*option_n)++;
// 	if (cmd[1][i] != '\0')
// 	{
// 		*option_n = 0;
// 		return ;
// 	}
// 	*option_n = 1;
// 	(*idx)++;
// }

void	check_echo_option(char *cmd, int *option_n, int *idx)
{
	int	i;

	i = 0;
	if (cmd[i] != '-')
		return ;
	while (cmd[++i] == 'n')
		(*option_n)++;
	if (cmd[i] != '\0')
	{
		*option_n = 0;
		return ;
	}
	*option_n = 1;
	(void)idx;
	//(*idx)++;
}

void	built_in_echo(t_command **cmd, t_env *env_list)
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
		{
			check_echo_option((*cmd)->word[idx], &option_n, &idx);
			if (option_n == 0)
				ft_putstr_fd((*cmd)->word[idx], 1);
			if ((*cmd)->word[idx + 1] != NULL)
				ft_putchar_fd(' ', 1);
		}
		if (option_n == 0)
			ft_putchar_fd('\n', 1);
	}
	env_list->status = 0;
	return ;
}
