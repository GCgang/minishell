/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:55:36 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/20 14:56:02 by jaehjoo          ###   ########.fr       */
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

#endif
