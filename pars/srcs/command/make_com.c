/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:46 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/12 21:10:53 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pars.h"
#include "sys/stat.h"

static int	init_command(t_command **com)
{
	(*com) = (t_command *)malloc(sizeof(t_command));
	if (*com == 0)
		return (err_msg("Error : Malloc failed(init_command)", 1, 0));
	(*com)->word = 0;
	(*com)->redir = 0;
	(*com)->redir_val = 0;
	(*com)->path = 0;
	(*com)->std_in = 0;
	(*com)->std_out = 1;
	(*com)->backup_fd = 0;
	(*com)->pipe = 0;
	(*com)->pipe_fd[0] = 0;
	(*com)->pipe_fd[1] = 0;
	(*com)->heredoc_fd = 0;
	(*com)->in_file_fd = 0;
	(*com)->out_file_fd = 0;
	(*com)->std_in_dup = 0;
	(*com)->std_out_dup = 1;
	(*com)->next = 0;
	return (0);
}

static void	chk_pipe(t_token **token, t_command *last)
{
	t_token		*tmp;
	t_command	*new_com;

	last->pipe = 1;
	tmp = *token;
	*token = (*token)->next;
	lstdelone_token(tmp);
	init_command(&new_com);
	last->next = new_com;
}

int	make_com(t_token **token, t_env **env_list, t_command **com)
{
	t_command	*tmp;

	if (init_command(com) || word_cnt(token, *com) || pars_com(token, *com))
		return (1);
	while ((*token) != 0 && (*token)->type == 'p')
	{
		tmp = *com;
		while (tmp->next != 0)
			tmp = tmp->next;
		chk_pipe(token, tmp);
		tmp = *com;
		while (tmp->next != 0)
			tmp = tmp->next;
		if (word_cnt(token, tmp) || pars_com(token, tmp))
			return (1);
	}
	return (record_builtin(com, *env_list) || record_path(com, *env_list));
}
