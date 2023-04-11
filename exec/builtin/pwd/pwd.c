/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <jun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:27:03 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/10 23:22:49 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pwd.h"

void	built_in_pwd(t_env *env_list)
{
	char	*dir;

	(void)env_list;
	dir = getcwd(NULL, PATH_MAX);
	if (dir == NULL)
	{
		perror("Minisehll: pwd: ");
		g_exit_status = 1;
		free(dir);
		return ;
	}
	ft_putstr_fd(dir, 1);
	ft_putchar_fd('\n', 1);
	free(dir);
	g_exit_status = 0;
}
