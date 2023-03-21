/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_oper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:45:12 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/21 15:45:13 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pars.h"

static int	pars_in(t_command *com, t_env **env_list)
{
	int	fd;

	if (ft_strncmp(com->oper, "<", 2) == 0)
	{
		fd = open(com->oper_val, O_RDONLY);
		if (fd < 0)
			return (-1);
		if (com->std_in != 0)
			close(com->std_in);
		com->std_in = fd;
	}
	else if (ft_strncmp(com->oper, "<<", 3) == 0)
		return (heredoc(com, env_list));
	return (0);
}

static void	pars_out(t_command *com)
{
	int	fd;

	fd = 0;
	if (ft_strncmp(com->oper, ">", 2) == 0)
		fd = open(com->oper_val, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (ft_strncmp(com->oper_val, ">>", 3) == 0)
		fd = open(com->oper_val, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (com->std_out != 1)
		close(com->std_out);
	com->std_out = fd;
}

static int	pars_redirection(t_token **token, t_command *com,
	t_token **tmp, t_env **env_list)
{
	if (com->oper_val != 0)
		free(com->oper_val);
	com->oper_val = ft_strdup((*token)->val);
	com->val_type = (*token)->type;
	*tmp = *token;
	*token = (*token)->next;
	lstdelone_token(*tmp, &free);
	if (ft_strncmp(com->oper, ">", 2) == 0
		|| ft_strncmp(com->oper, ">>", 3) == 0)
		pars_out(com);
	else
		return (pars_in(com, env_list));
	return (0);
}

int	pars_oper(t_token **token, t_env **env_list, t_command *com)
{
	t_token	*tmp;
	int		res;

	res = 0;
	while (*token != 0 && (*token)->type != 'p' && res >= 0)
	{
		if (com->oper != 0)
			free(com->oper);
		com->oper = ft_strdup((*token)->val);
		tmp = *token;
		*token = (*token)->next;
		lstdelone_token(tmp, &free);
		if (*token != 0 && ((*token)->type == 'v'
				|| (*token)->type == 'h' || (*token)->type == 'H'))
			res = pars_redirection(token, com, &tmp, env_list);
		else
		{
			printf("Minishell$ Syntax error Undefined value after operator\n");
			return (-2);
		}
	}
	return (res);
}
