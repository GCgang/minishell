#include "../include/pars.h"

static void	init_command(t_command **com)
{
	(*com) = (t_command *)malloc(sizeof(t_command));
	(*com)->order = 0;
	(*com)->word = 0;
	(*com)->oper = 0;
	(*com)->oper_val = 0;
	(*com)->path = 0;
	(*com)->path_err = 0;
	(*com)->builtin = 0;
	(*com)->std_in = 0;
	(*com)->std_out = 1;
	(*com)->std_err = 2;
	(*com)->pipe = 0;
	(*com)->pipe_out = 0;
	(*com)->pipe_in = 0;
	(*com)->next = 0;
}

static void	pars_pipe(t_token **token, t_command *last)
{
	t_token		*tmp;
	t_command	*new_com;
	int			fd[2];

	last->pipe = 1;
	tmp = *token;
	*token = (*token)->next;
	lstdelone_token(tmp, &free);
	if (pipe(fd) == -1)
		return ;
	init_command(&new_com);
	last->next = new_com;
	last->pipe_out = fd[1];
	last->next->pipe_in = fd[0];
}

int	make_com(t_token **token, t_env **env_list, t_command **com)
{
	t_command	*tmp;
	int			order;

	order = 0;
	init_command(com);
	word_cnt(token, *com);
	if (pars_com(token, env_list, *com) == -1)
		return (-1);
	(*com)->order = order;
	while ((*token) != 0 && ft_strncmp((*token)->val, "|", 2) == 0)
	{
		tmp = *com;
		while (tmp->next != 0)
			tmp = tmp->next;
		pars_pipe(token, tmp);
		tmp = *com;
		while (tmp->next != 0)
			tmp = tmp->next;
		if (pars_com(token, env_list, tmp) == -1)
			return (-1);
		order++;
		tmp->order = order;
	}
	record_extra(*com, *env_list);
	return (0);
}
