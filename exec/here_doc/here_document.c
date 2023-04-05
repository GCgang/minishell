/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_document.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:13:30 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/05 20:51:04 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/here_doc.h"

void	check_here_document(t_command *process)
{
	t_command	*tmp_proc;
	int			idx;

	tmp_proc = process;
	while (tmp_proc != NULL)
	{
		idx = -1;
		while (tmp_proc->redir[++idx] != NULL)
		{
			if (ft_strcmp((tmp_proc)->redir[idx], "<<") == 0)
			{
				tmp_proc->heredoc_fd = open((tmp_proc)->redir_val[idx], \
										O_WRONLY | O_CREAT | O_APPEND, 0644);
				if (tmp_proc->heredoc_fd == -1)
				{
					perror("Minishell: temp: ");
					g_exit_status = 1;
					return ;
				}
				here_document(tmp_proc, idx);
				free(tmp_proc->redir[idx]);
				tmp_proc->redir[idx] = ft_strdup("<");
			}
		}
		tmp_proc = tmp_proc->next;
	}
}

void	here_document(t_command *process, int idx)
{
	char	*line;
	char	*limiter;

	limiter = process->redir_val[idx];
	parent_std_io_copy(process);
	exec_signal(1);
	while (1)
	{
		ft_putstr_fd("> ", 2);
		line = get_next_line(0);
		if (ft_strncmp(line, limiter, (ft_strlen(line) - 1)) == 0 || \
		line == NULL)
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, process->heredoc_fd);
		free(line);
	}
	close(process->heredoc_fd);
	exec_signal(0);
	parent_std_io_reset(process);
}
