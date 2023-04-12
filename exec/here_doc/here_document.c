/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_document.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:13:30 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/12 15:57:33 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/here_doc.h"

char	*open_here_doc_file(t_command *process, int idx)
{
	char	*here_doc_file;

	here_doc_file = ft_strjoin("/tmp/", process->redir_val[idx]);
	if (here_doc_file == NULL)
	{
		ft_putstr_fd("Error : Malloc failed(open_here_doc_file)", 2);
		g_exit_status = 1;
		return (NULL);
	}
	process->heredoc_fd = open(here_doc_file, \
							O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (process->heredoc_fd == -1)
	{
		ft_putstr_fd("Minishell: ", 2);
		ft_putstr_fd(here_doc_file, 2);
		ft_putstr_fd(": ", 2);
		perror("");
		free(here_doc_file);
		g_exit_status = 1;
		return (NULL);
	}
	return (here_doc_file);
}

int	update_redir(t_command *process, int idx, char *here_doc_file_name)
{
	free(process->redir[idx]);
	process->redir[idx] = ft_strdup("<");
	if (process->redir[idx] == NULL)
	{
		ft_putstr_fd("Error : Malloc failed(update_redir)", 2);
		g_exit_status = 1;
		return (-1);
	}
	free(process->redir_val[idx]);
	process->redir_val[idx] = here_doc_file_name;
	return (1);
}

int	check_here_document(t_command *process)
{
	int			idx;
	char		*here_doc_file;

	if (process->redir == NULL || process->redir_val == NULL)
		return (1);
	while (process != NULL)
	{
		idx = -1;
		while (process->redir[++idx] != NULL)
		{
			if (ft_strcmp((process)->redir[idx], "<<") == 0)
			{
				here_doc_file = open_here_doc_file(process, idx);
				if (here_doc_file == NULL || here_document(process, idx) == -1
					|| update_redir(process, idx, here_doc_file) == -1)
				{
					free(here_doc_file);
					return (-1);
				}
				close(process->heredoc_fd);
			}
		}
		process = process->next;
	}
	return (1);
}

int	here_document(t_command *process, int idx)
{
	char	*line;
	char	*limiter;

	limiter = process->redir_val[idx];
	exec_signal(2);
	parent_std_io_copy(process);
	g_exit_status = 0;
	while (1)
	{
		line = readline("> ");
		if (ft_strcmp(line, limiter) == 0 || line == NULL)
		{
			free(line);
			parent_std_io_reset(process);
			close(process->heredoc_fd);
			if (line == NULL)
				return (-1);
			else
				break ;
		}
		ft_putstr_fd(line, process->heredoc_fd);
		ft_putchar_fd('\n', process->heredoc_fd);
		free(line);
	}
	return (1);
}

void	unlink_file(t_command *cmd)
{
	t_command	*process;
	int			i;

	process = cmd;
	while (process != NULL)
	{
		if (process->redir_val != NULL)
		{
			i = -1;
			while (process->redir_val[++i] != NULL)
			{
				if (ft_strncmp("/tmp/", (process)->redir_val[i], 5) == 0)
				{
					unlink((process)->redir_val[i]);
				}
			}
		}
		process = process->next;
	}
}
