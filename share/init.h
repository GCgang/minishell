/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:49:55 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/12 21:26:21 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "struct.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../pars/include/pars.h"
# include "../exec/include/execute.h"

int		g_exit_status;

char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);

void	lstadd_front_env(t_env **lst, t_env *new);
void	lstadd_back_env(t_env **lst, t_env *new);
void	lstdelone_env(t_env *lst);
void	lstclear_env(t_env **lst);
void	lstclear_com(t_command **lst);
t_env	*lstnew_env(char *name, char *val);
void	lstdelone_env_elem(t_env *before, t_env *now);
void	clear_all(t_token **token, t_env **env_list, t_command **com);

void	init_signal(void);
void	heredoc_sigint_handler(int sig);
void	exec_signal(int phase);
int		init_env(char **envp, t_env **env_list);
int		err_msg(char *str, int newline, int **fr);

#endif
