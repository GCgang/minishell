/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:27:00 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/20 14:27:37 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

void	init_envp()
{
	//get_key()
	//get_value()
	//update_envp()
}

int	check_export_syntax(char *variable)
{
	if (ft_isalpha(*variable) == 0 && *variable != '_')
		return (0);
	while (*variable)
	{
		if (ft_isalpha(*variable) == 0\
		|| ft_isdigit(*variable) == 0\
		|| *variable != '_')
			return (0);
		variable++;
	}
	return (1);
}

void	built_in_export(char **envp)
{
	char	*variable;

	variable = "export";
	if (variable == NULL)
	{
		//sort_envp()
		//print_envp() // declare -x
		//delete_envp()
		//g_exit_status = 0;
	}
	else
	{
		// export "variable"
		while (variable)
		{
			if (check_export_syntax(variable) == 0)
			{
				ft_putstr_fd("not a valid identifier", 2);
				//g_exit_status = 1;
			}
			else
			{
				//init_envp(cmd);
				//g_exit_status = 0;
			}
		}
	}
}
