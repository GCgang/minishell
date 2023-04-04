/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:00:55 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/04 19:28:34 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#	ifndef EXECUTE_H
# define EXECUTE_H

# include "../../share/init.h"
# include <string.h>
# include "builtin.h"
# include "redirection.h"
# include "here_doc.h"

int				is_built_in(char *word);
void			only_built_in(t_command *process, t_env **env_list);
void			execute_built_in(t_command **cmd, t_env **env_list);

char			*check_cmd(t_command *process, t_env **env_list);
void			run_execve(t_command *process, t_env **env_list, char **envp);

void			execute_binary(t_command **process, \
											t_env **env_list, int cmd_cnt, char **envp);
void			child_process(t_command **process, \
											t_env **env_list, int cmd_cnt, char **envp);
void			parent_process(t_command **process);
void			exec(t_command **cmd, t_env **env_list, char **envp);
void			wait_process(int cmd_cnt);

int				ft_strcmp(char *s1, char *s2);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
long long		ft_atol(const char *str);

#endif