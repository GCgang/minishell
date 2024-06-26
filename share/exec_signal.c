/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:47:17 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/12 22:01:20 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static void	exec_sigint_handler(int sig)
{
	(void)sig;
	printf("\n");
	g_exit_status = 130;
}

static void	exec_sigquit_handler(int sig)
{
	(void)sig;
	g_exit_status = 131;
	printf("Quit: 3\n");
}

static void	heredoc_handler(int sig)
{
	(void)sig;
	printf("\n");
	g_exit_status = 130;
	close(0);
}

void	exec_signal(int phase)
{
	if (phase == 0)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (phase == 1)
	{
		signal(SIGINT, exec_sigint_handler);
		signal(SIGQUIT, exec_sigquit_handler);
	}
	else
	{
		signal(SIGINT, heredoc_handler);
		signal(SIGQUIT, SIG_IGN);
	}
}
