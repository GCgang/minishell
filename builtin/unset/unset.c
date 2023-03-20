/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <jun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:27:05 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/20 11:25:37 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unset.h"

int	check_unset_syntax(char *variable)
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

void	built_in_unset(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		if (check_unset_syntax(envp[i]) == 0)
		{
			ft_putstr_fd("not a valid identifier", 2);
			//g_exit_status = 1;
		}
		else
		;	
			//delete_envp(envp);
	}
	return ;
}
