/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:57:22 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/12 21:10:13 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static void	introduce(void)
{
	printf("                                         ");
	printf("\033[0;36mminishell\033[0m\n");
	printf("                                         ");
	printf("\033[0;36mby_hyeoan\033[0m\n");
	printf("               ⣀⣠⣤⣤⣤⣤⣄⣀                 ");
	printf("\033[0;36mby_jaehjoo\033[0m\n");
	printf("           ⢀⣠⣶⠿⠛⠉⠁ ⢰⡇⠉⠛⠿⣦⡀                        \n");
	printf("         ⣀⣴⠟⠋⢀⡀ ⢀⣠⣤⣿⣷⣴⣷⡀⠹⣿⡄                       \n");
	printf("       ⣠⡾⠛⠁ ⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡷⠞⠛⢿⣶⣦⣄                    \n");
	printf("    ⣀⣤⡾⠋    ⠹⣿⡟⢻⠏⣾⠃⡿⠋⣹⣿⣤⣶⣦⣤⡿⢿⣿⣷                   \n");
	printf(" ⡶⠶⠟⠋⠁⣀⡀     ⠈⠻⣾⣠⣇⣼⢁⡞⢉⣿⣿⣿⣿⡏⢰⣿⣿⡋                   \n");
	printf("     ⠸⣿⠟⢷⡄ ⢠⣶⡶⢀⣿⣿⣿⣷⣾⠁⣾⠋  ⠙⢿⣿⣿⡿⠃                 ⢀⣴\n");
	printf(" ⣴⣶⣶⣦⣄⣹⣿⣟⠻⣆⠘⣿⣿⣿⣿⣿⣿⡿⣿ ⣿   ⠿⢸⣿⣯⣴⡶               ⢀⣴⠟⠁\n");
	printf("⢸⣿⣿⣿⣿⣿⡟⢻⣿⣿⣿⣶⣤⣽⣿⣿⣿⣿⣧⠸⣧⣿⡄   ⣈⣉⡉⠁              ⢀⣴⠟⠁ ⣠\n");
	printf("⠘⣿⣿⡿⢿⣿⣿⣦⠻⣟⠻⣿⣿⣿⡿⠟⠉⠉⠙⠳⣿⣿⣿⣄  ⣿⣿⡗             ⣠⣴⠟⠁  ⣴⣯\n");
	printf(" ⠘⢿⣷⣼⣿⣿⣿⣷⣾⣷⣿⠿⠋      ⠈⠛⢿⣿⣷⣄ ⠁           ⣀⣤⡾⠋⠁ ⣠⣴⣿⣷⣤\n");
	printf("   ⠙⠿⢿⣿⣿⣿⠿⠛⠁     ⡀     ⠉⠻⢿⣿⣶⣤⣤⣀⣀⣀⣀⣀⣤⣤⣶⠿⠛⣁⣀⣀⡴⠿⢿⣿⡿⢋⣡\n");
	printf("   ⣀      ⢼⣦⡀⠠⣤⡶⠟⠃⢀⣶⣿⣷⣦⡀⠰⣄⢸⣿⣝⡛⠛⠛⠛⠛⠋⠉⠁   ⠙⣩⣥⣶⣶⡿⢋⣿⡿⠟\n");
	printf("   ⠙⣿⣶⣛⣵⣶⣄ ⠙⠇⡀ ⣶⣦⣀⣾⠁⢻⡟⢿⣿⣦⡈⢻⡟⠻⢯⡳⢤⣀⣠⣴⣶⣶⣦⣤⣼⣿⣭⣍⠉⣁⣀⣈⣉⣀⣿\n");
	printf(" ⢀⣴⣾⣿⠋⢹⣟⣀⣿⣷⣾⣛⣉⣼⣿⣿⣿⣻⣧⡀⠳ ⠙⢿⣿⣿⣿⣷⣤⣍⣀⡙⣿⣿⣦⣿⣿⣿⠏⠛⠋⢁⣈⣛⣛⣋⣉⣭⣤\n");
	printf(" ⢸⣿⣿⠃ ⠘⢻⣿⣿⣿⣿⡏⢁⣠⣤⣤⣿⣿⣿⡿ ⣈⣓⠦⣉⣿⣿⣿⣿⣿⣿⣿⡿⠿⠟⠛⠉⢁⣴⠞⠛⠋⠉⠉⣉⣉⣉⣉⣉\n");
	printf(" ⠈⠛⠁   ⠘⠛⠛⠛⠛⠛⠛⠛⠉⠉⠛⠛⠙⠓⠚⠛⠛⠃  ⠉⠉⠙⠛⠒⠚⠒⠒⠛⠛⠚⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛\n");
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

	(void)av;
	if (init_chk(ac, envp, &env_list) != 0)
		return (0);
	while (1)
	{
		line = readline("Minishell$ ");
		if (!line)
		{
			printf("exit\n");
			break ;
		}
		if (*line != 0)
			add_history(line);
		pars_line(line, &env_list, envp);
	}
	clear_all(0, &env_list, 0);
	return (0);
}
