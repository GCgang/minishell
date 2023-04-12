/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:27:03 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/12 17:10:08 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pwd.h"

void	built_in_pwd(void)
{
	char	*dir;

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
