/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:27:03 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/16 22:44:56 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pwd.h"

void	built_in_pwd(void)
{
	char	*buf;
	char	*dir;

	buf = NULL;
	dir = getcwd(buf, PATH_MAX);
	if (dir == NULL)
	{} ;
		/*
		if (pid > 0)
			perror("DIR PATH ERROR")
		else if (pid == 0)
			exit(1);
		*/
	printf("%s\n", dir);
	free(dir);
	return ;
}
