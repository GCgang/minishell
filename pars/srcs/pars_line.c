/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:45:03 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/31 19:14:15 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pars.h"

static void	test_print_all(t_env **env_list, t_command **com)
{
	t_command	*tmp2;
	t_env		*tmp1;
	int			idx;

	tmp1 = *env_list;
	tmp2 = *com;
	idx = 0;
	while (tmp1)
	{
		printf("env : name->%s, val->%s, mean->%c, status->%d\n", tmp1->name, tmp1->val, tmp1->mean, tmp1->status);
		tmp1 = tmp1->next;
	}
	while (tmp2)
	{
		printf("com1 : word->");
		idx = 0;
		while (tmp2->word != 0 && tmp2->word[idx])
		{
			printf("%s, %p", tmp2->word[idx], tmp2->word[idx]);
			idx++;
		}
		printf("\n");
		printf("com2 : ");
		idx = -1;
		while (tmp2->path != 0 && tmp2->path[++idx])
			printf("%s ", tmp2->path[idx]);
		printf("\n");
		idx = -1;
		printf("redir : ");
		while (tmp2->redir != 0 && tmp2->redir[++idx])
			printf("%s ", tmp2->redir[idx]);
		printf("\n");
		idx = -1;
		printf("redir_val : ");
		while (tmp2->redir_val != 0 && tmp2->redir_val[++idx])
			printf("%s ", tmp2->redir_val[idx]);
		printf("\n");
		printf("val_type->%c\n", tmp2->val_type);
		printf("com3 : builtin->%c, std_in->%d, std_out->%d, std_err->%d, pipe->%d, pipe_in->%d, pipe_out->%d\n", tmp2->builtin, tmp2->std_in, tmp2->std_out, tmp2->std_err, tmp2->pipe, tmp2->pipe_fd[0], tmp2->pipe_fd[1]);
		tmp2 = tmp2->next;
	}
}

static void	cpy_special(char *spe, char *tmp)
{
	int	idx;

	idx = 0;
	while (tmp[idx])
	{
		spe[idx] = tmp[idx];
		idx++;
	}
	spe[idx] = 0;
}

void	pars_line(char *line, t_token **token, t_env **env_list)
{
	char		spe[5];
	t_command	*com;

	*token = 0;
	com = 0;
	cpy_special(spe, "<> |");
	if (chk_close_quote(line) > 0)
	{
		if (make_token(line, spe, token) || mix_token(token, 0)
			|| rotate_env_token(token, env_list) || mix_token(token, 1)
			|| trim_token(token) || chk_oper_token(*token)
			|| removing_quote(token))
		{
			lstclear_token(token);
			return ;
		}
		if (make_com(token, env_list, &com) == 0)
		{
			test_print_all(env_list, &com);
			exec(&com, env_list);
		}
	}
	clear_all(token, 0, &com);
}
