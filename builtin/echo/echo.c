/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:26:52 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/17 20:00:03 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "echo.h"

// void	check_echo_option(char **str, int *option_n)
// {
// 	int	i;

// 	i = 0;
// 	if (**str != '-')
// 		return ;
// 	else
// 		(*str)++;
// 	while (**str == 'n')
// 	{
// 		(*str)++;
// 		(*option_n)++;
// 	}
// 	if (**str != ' ')
// 	{
		
// 	}
// 	if (**str == ' ' && *option_n > 0)
// 	{
// 		*option_n = 1;
// 		return ;
// 	}
// }
void	check_echo_option(char **str, int *option_n)
{
	int	i;

	i = 0;
	if (str[0][i] != '-')
		return ;
	while (str[0][++i] == 'n')
		(*option_n)++;
	if (str[0][i] != ' ')
	{
		*option_n = 0;
		return ;
	}
	if (str[0][i] == ' ' && *option_n > 0)
	{
		while (**str != ' ')
			(*str)++;
		*option_n = 1;
		return ;
	}
}

void	built_in_echo(char **argv)
{
	int		i;
	int		option_n;
	char	*str;

	i = -1;
	option_n = 0;
	if (argv[2] == NULL || argv[2][0] == '\0')
		ft_putchar_fd('\n', 1);
	else
	{
		check_echo_option(&argv[2], &option_n);
		ft_putstr_fd(argv[2], 1);
		if (option_n == 0)
			ft_putchar_fd('\n', 1);
	}
	//exit_status = 0;
	return ;
}
