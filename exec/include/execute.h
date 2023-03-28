/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:00:55 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/28 17:13:49 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#	ifndef EXECUTE_H
# define EXECUTE_H

# include "../../share/init.h"
# include <string.h>
# include "builtin.h"

//void	execute_built_in(char **argv, char **envp);
void			exec(t_command **cmd, t_env **env_list);
void			execute_built_in(t_command **cmd, t_env **env_list, int pipe);

int				is_built_in(char **word);
char			*check_cmd(t_command *process);
void			run_execve(t_command *process);
void			child_process(t_command **process, t_env **env_list);
void			parent_process(t_command **cmd);
void			execute_binary(t_command **cmd, t_env **env_list);

int				ft_strcmp(char *s1, char *s2);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
long long		ft_atol(const char *str);

#endif