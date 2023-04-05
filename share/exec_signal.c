/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:47:17 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/05 19:45:37 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static void	exec_handler(int sig)
{
	if (sig == SIGINT)
		printf("^C\n");
	if (sig == SIGQUIT)
		printf("^\\Quit: 3\n");
}

static void	heredoc_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("^C\n");
		close(0);
	}
	if (sig == SIGQUIT)
	{
		rl_redisplay();
	}
}

void	exec_signal(int phase)
{
	if (phase == 0)
	{
		signal(SIGINT, exec_handler);
		signal(SIGQUIT, exec_handler);	
	}
	else
	{
		signal(SIGINT, heredoc_handler);
		signal(SIGQUIT, heredoc_handler);
	}
}
