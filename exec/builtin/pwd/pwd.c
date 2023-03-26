/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:27:03 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/26 19:54:33 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pwd.h"

void	built_in_pwd(t_env *env_list)
{
	char	*dir;

	dir = getcwd(NULL, PATH_MAX);
	ft_putstr_fd(dir, 1);
	ft_putchar_fd('\n', 1);
	free(dir);
	env_list->status = 0;
}
