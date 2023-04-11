/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:00:55 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/11 16:09:03 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#	ifndef EXECUTE_H
# define EXECUTE_H

# include "../../share/init.h"
# include "builtin.h"
# include "redirection.h"
# include "here_doc.h"

enum	e_EXECVE_CMD_ERROR
{
	FILENAME_ARGUMENT_REQUIRED = 1,
	IS_A_DIRECTORY,
	NO_SUCH_FILE_OR_DIRECTORY,
	COMMAND_NOT_FOUND	
};

int				is_built_in(t_command *process);
void			only_built_in(t_command **process, t_env **env_list, \
																int cmd_cnt);
void			execute_built_in(t_command **cmd, t_env **env_list, \
																int cmd_cnt);

char			*check_cmd(t_command *process, t_env **env_list);
void			run_execve(t_command *process, t_env **env_list, char **envp);
void			execve_error(int err_flag, char *err_word, int exit_status);

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
long long		ft_atol(char *str);

#endif