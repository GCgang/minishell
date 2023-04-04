/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_io_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:58:12 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/04 15:01:35 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/redirection.h"

void	child_stdin_dup2(int fd1, int fd2)
{
	dup2(fd1, fd2);
	close(fd1);
}

void	child_stdout_dup2(int fd1, int fd2)
{
	dup2(fd1, fd2);
	close(fd1);
}
