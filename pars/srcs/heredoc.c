/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:41 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/21 18:26:48 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pars.h"

static char	*extra_line(char *line, t_env *env_list)
{
	t_token	*tmp;
	char	*str;

	tmp = (t_token *)malloc(sizeof(t_token));
	if (tmp == 0)
		return (0);
	tmp->val = line;
	tmp->type = 'w';
	tmp->quote = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (tmp->quote == 0)
		return (0);
	tmp->quote[ft_strlen(line)] = 0;
	tmp->quote = (char *)ft_memset(tmp->quote, '0', ft_strlen(line));
	tmp->next = 0;
	env_search(tmp, env_list);
	free(tmp->quote);
	str = tmp->val;
	free(tmp);
	return (str);
}

static void	chain_hd(t_command *com, t_env *env_list, int hd)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_strncmp(line, com->oper_val,
				ft_strlen(com->oper_val) + 1) == 0)
			break ;
		if (com->val_type == 'h')
			line = extra_line(line, env_list);
		write(hd, line, ft_strlen(line));
		write(hd, "\n", 1);
		free(line);
	}
	if (line != 0)
		free(line);
}

static void	child_hd(t_command *com, t_env **env_list, int *hd)
{
	signal(SIGINT, heredoc_sigint_handler);
	close(hd[0]);
	chain_hd(com, *env_list, hd[1]);
	close(hd[1]);
	exit(0);
}

static int	parent_hd(t_command *com, int *hd)
{
	int	status;

	signal(SIGINT, SIG_IGN);
	wait(&status);
	close(hd[1]);
	if (WIFEXITED(status))
	{
		status = WEXITSTATUS(status);
		if (status == 1)
			return (-3);
		else
			com->std_in = dup(hd[0]);
		close(hd[0]);
	}
	init_signal();
	return (0);
}

int	heredoc(t_command *com, t_env **env_list)
{
	int	pid;
	int	hd[2];
	int	idx;

	idx = pipe(hd);
	if (idx == -1)
		exit(1);
	pid = fork();
	if (pid == 0)
		child_hd(com, env_list, hd);
	else
		return (parent_hd(com, hd));
	return (0);
}
