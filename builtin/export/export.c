/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:27:00 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/21 15:48:31 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

void	init_envp()
{
	//get_name()
	//get_value()
	//update_envp()
}

int	check_export_syntax(char *cmd)
{
	if (ft_isalpha(*cmd) == 0 && *cmd != '_')
		return (0);
	while (*cmd)
	{
		if (ft_isalpha(*cmd) == 0
			|| ft_isdigit(*cmd) == 0
			|| *cmd != '_')
		{
			return (0);
		}
		cmd++;
	}
	return (1);
}

void	built_in_export(t_command **cmd, t_env *env_list)
{
	if ((*cmd)->word[1] == NULL)
	{
		//sort_envp()
		//print_envp() // declare -x
		//delete_envp()
		//g_exit_status = 0;
	}
	else
	{
		while ((*cmd)->word[1])
		{
			if (check_export_syntax((*cmd)->word[1]) == 0)
			{
				ft_putstr_fd("not a valid identifier", 2);
				env_list->status = 1;
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
