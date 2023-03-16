/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:27:03 by hyeoan            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/03/16 22:57:21 by hyeoan           ###   ########.fr       */
=======
/*   Updated: 2023/03/16 22:44:56 by hyeoan           ###   ########.fr       */
>>>>>>> 08698c52d3c56c202fb69a561ab072db58466aa3
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
