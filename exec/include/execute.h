/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:00:55 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/22 16:22:46 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

// gcc execute.c strcmp.c ../builtin/cd/cd.c ../builtin/echo/echo.c ../builtin/env/env.c ../builtin/exit/exit.c ../builtin/export/export.c ../builtin/pwd/pwd.c ../builtin/unset/unset.c
#	ifndef EXECUTE_H
# define EXECUTE_H

# include "../../share/init.h"
# include <string.h>
# include "builtin.h"

//void	execute_built_in(char **argv, char **envp);
void	exec(t_command **cmd, t_env **env_list, pid_t pid);
void	execute_built_in(t_command **cmd, t_env **env_list, pid_t pid);
int		ft_strcmp(char *s1, char *s2);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int	    ft_isalpha(int c);

#endif