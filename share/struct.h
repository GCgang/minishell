/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:55:36 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/10 12:51:29 by jaehjoo          ###   ########.fr       */
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
	struct s_env	*next;
}	t_env;

typedef struct s_command
{
	char				**word;
	char				**path;
	char				**redir;
	char				**redir_val;
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
	struct s_command	*next;
}	t_command;

#endif
