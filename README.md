# minishell

1. pars에서 exec 수정한 사항

가. execute.c
void	wait_process(int cmd_cnt)
{
	int	status;

	exec_signal(0);
	status = 0;
	while (cmd_cnt--)
		waitpid(-1, &status, 0);
	init_signal();
}

나. here_document.c
void	here_document(t_command *process, int idx)
{
	char	*line;
	char	*limiter;

	limiter = process->redir_val[idx];
	exec_signal(1);
	while (1)
	{
		line = readline("> ");
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
}

다. Makefile get_next_line, get_next_line_utils 삭제

라. heredoc에서 get_next_line, get_next_line_utils source 삭제