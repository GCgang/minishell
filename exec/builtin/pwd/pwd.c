/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:27:03 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/31 16:30:12 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pwd.h"

void	built_in_pwd(t_command **cmd)
{
	char	*dir;

	dir = getcwd(NULL, PATH_MAX);
	// ft_putstr_fd(dir, 1);
	// ft_putchar_fd('\n', 1);
	ft_putstr_fd(dir, (*cmd)->std_out);
	ft_putchar_fd('\n', (*cmd)->std_out);
	free(dir);
	g_exit_status = 0;
}
