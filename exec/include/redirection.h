/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:11:14 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/04 15:01:52 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef REDIRECTION_H
# define REDIRECTION_H

# include "execute.h"

int		redirection(t_command **cmd);
int		i_redirection(t_command **cmd, int idx);
int		o_trunc_redirection(t_command **cmd, int idx);
int		o_append_redirection(t_command **cmd, int idx);
void	parent_std_io_copy(t_command *cmd);
void	parent_std_io_reset(t_command *cmd);
void	child_stdin_dup2(int fd1, int fd2);
void	child_stdout_dup2(int fd1, int fd2);

#endif