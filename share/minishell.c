/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:57:22 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/07 16:44:02 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static void	introduce(void)
{
}

static int	init_chk(int ac, char **envp, t_env **env_list)
{
	if (ac > 1)
		return (err_msg("Error : You don't need to insert argument", 1, 0));
	init_signal();
	if (init_env(envp, env_list) == 1)
		return (err_msg("Error : Malloc failed(init_env)", 1, 0));
	introduce();
	return (0);
}

int	main(int ac, char **av, char**envp)
{
	char	*line;
	t_env	*env_list;
	t_token	*tokens;

	(void)av;
	if (init_chk(ac, envp, &env_list) != 0)
		return (0);
	while (1)
	{
		line = readline("Minishell$ ");
		if (!line)
		{
			printf("exit\n");
			return (0);
		}
		if (*line != 0)
			add_history(line);
		pars_line(line, &tokens, &env_list, envp);
	}
	clear_all(&tokens, &env_list, 0);
	return (0);
}
