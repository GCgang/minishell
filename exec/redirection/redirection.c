/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:38:46 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/05 21:12:40 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/redirection.h"

int	redirection(t_command **cmd)
{
	t_command	*process;
	int			idx;

	process = (*cmd);
	idx = -1;
	if (process->redir == NULL || process->redir_val == NULL)
		return (1);
	while (process->redir[++idx] != NULL)
	{
		if (ft_strcmp(process->redir[idx], "<") == 0)
		{
			process->std_in = i_redirection(cmd, idx);
			if (process->std_in == 0)
				return (0);
		}
		else if (ft_strcmp(process->redir[idx], ">") == 0)
			process->std_out = o_trunc_redirection(cmd, idx);
		else if (ft_strcmp(process->redir[idx], ">>") == 0)
			process->std_out = o_append_redirection(cmd, idx);
	}
	return (1);
}

int	i_redirection(t_command **cmd, int idx)
{
	int	infile_fd;

	infile_fd = open((*cmd)->redir_val[idx], O_RDONLY);
	if (infile_fd == -1)
	{
		ft_putstr_fd("Minishell: ", 2);
		ft_putstr_fd((*cmd)->redir_val[idx], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		g_exit_status = 1;
		return (0);
	}
	g_exit_status = 0;
	return (infile_fd);
}

int	o_trunc_redirection(t_command **cmd, int idx)
{
	int	outfile_fd;

	outfile_fd = open((*cmd)->redir_val[idx], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd == -1)
	{
		ft_putstr_fd("Minishell: ", 2);
		ft_putstr_fd((*cmd)->redir_val[idx], 2);
		ft_putstr_fd(": ", 2);
		perror("");
		g_exit_status = 1;
		return (1);
	}
	g_exit_status = 0;
	return (outfile_fd);
}

int	o_append_redirection(t_command **cmd, int idx)
{
	int	outfile_fd;

	outfile_fd = open((*cmd)->redir_val[idx], \
						O_RDWR | O_CREAT | O_APPEND, 0644);
	if (outfile_fd == -1)
	{
		ft_putstr_fd("Minishell: ", 2);
		ft_putstr_fd((*cmd)->redir_val[idx], 2);
		ft_putstr_fd(": ", 2);
		perror("");
		g_exit_status = 1;
		return (1);
	}
	g_exit_status = 0;
	return (outfile_fd);
}
