/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:55:36 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/04 17:28:40 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_token
{
	char			type;
	char			*val;
	char			*quote;
	struct s_token	*next;
}	t_token;

typedef struct s_env
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
	char				**path;
	int					path_err;
	char				**redir;
	char				**redir_val;
	char				val_type;
	char				builtin;
	int					std_in;
	int					std_out;
	int					backup_fd;
	int					heredoc_fd;
	int					std_in_dup;
	int					std_out_dup;
	int					in_file_fd;
	int					out_file_fd;
	int					pipe;
	int					pipe_fd[2];
	char				*err_buf;
	struct s_command	*next;
}	t_command;

#endif
