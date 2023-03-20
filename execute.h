/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:00:55 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/20 16:34:46 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

// gcc execute.c strcmp.c ../builtin/cd/cd.c ../builtin/echo/echo.c ../builtin/env/env.c ../builtin/exit/exit.c ../builtin/export/export.c ../builtin/pwd/pwd.c ../builtin/unset/unset.c
#	ifndef EXECUTE_H
# define EXECUTE_H

typedef struct	s_env
{
	char			*name;
	char			*val;
	char			mean;
	int				status;
	struct s_env	*next;
}	t_env;

typedef struct s_command
{
	int					order;
	char				**word;
	char				*path;
	int					path_err;
	char				*oper;
	char				*oper_val;
	char				val_type;
	char				builtin;
	int					std_in;
	int					std_out;
	int					std_err;
	int					std_in_dup1;
	int					std_out_dup1;
	int					pipe;
	int					pipe_in;
	int					pipe_out;
	struct s_command	*next;
}	t_command;

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include "builtin.h"

//void	execute_built_in(char **argv, char **envp);
void	execute_built_in(t_command **cmd, t_env *env_list, pid_t pid);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int	    ft_isalpha(int c);

#endif