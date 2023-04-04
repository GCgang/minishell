/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:11:12 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/04 13:03:33 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static void	cut_echo(void)
{
	struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(0, 0, &term);
}

static void	sigquit_handler(int sig)
{
	(void)sig;
	rl_redisplay();
}

static void	sigint_handler(int sig)
{
	(void)sig;
	g_exit_status = 1;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	heredoc_sigint_handler(int sig)
{
	(void)sig;
	g_exit_status = 1;
	printf("\n");
	exit(1);
}

void	init_signal(void)
{
	cut_echo();
	signal(SIGQUIT, sigquit_handler);
	signal(SIGINT, sigint_handler);
}
