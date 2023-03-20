/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <jun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:26:58 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/19 20:37:13 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

int check_exit_syntax(char *exit_val)
{
	int i;

	i = -1;
	while (exit_val[++i])
	{
		if (ft_isdigit(exit_val[i]) == 0)
			return (0);
	}
	return (1);
}

void built_in_exit(void)
{
	char *exit_val;
	int exit_status;
	int cmd_cnt;

	exit_val = "255";
	cmd_cnt = 1;
	// exit("255")
	if (check_exit_syntax(exit_val) && cmd_cnt == 1)
	{
		// g_exit_status = ft_atoi(exit_val);
		;
	}
	//exit("255test") or exit("255") test
	else if (check_exit_syntax(exit_val) && cmd_cnt >= 2)
	{
		ft_putstr_fd("too many arguments", 2);
		// g_exit_status = 1;
	}
	else
	{
		ft_putstr_fd("numeric argument required", 2);
		// g_exit_status = 255;
	}
	// exit (g_exit_status);
}
