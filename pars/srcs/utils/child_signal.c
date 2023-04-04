/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:24:54 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/04 14:32:33 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pars.h"

static void	revive_echo(void)
{
	struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag &= ECHOCTL;
	tcsetattr(0, 0, &term);
}

static void	child_sigint_handler(int sig)
{
	(void)sig;
	printf("\n");
}

static void	child_sigquit_handler(int sig)
{
	(void)sig;
}

void	child_signal(void)
{
	revive_echo();
	signal(SIGINT, child_sigint_handler);
	signal(SIGQUIT, child_sigquit_handler);
}
