/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:46 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/28 14:23:49 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pars.h"

/*
	make_com
	1. token 내용물을 command 구조체로 옮기는 작업을 한다
	2. init_command : 구조체 초기화, std_in, std_out, std_err는 기본 fd(0, 1, 2)로 초기화하고 나머지는 전부 0
	3. word_cnt : redirection, pipe, redirection 뒤에 위치한 토큰을 제외한 나머지 토큰을 순서대로 com->word에 분류
	4. pars_com : com->oper에는 redirection, com->oper_val에는 

	error 수정 필요
	1. word_cnt 미기입
	2. cat, ls error print
	 2-a. word_sep
	 2-b. if (word[0] == ls or cat) -> word[1] == option -> if (유효) return (error_buf(word[], 2)) else return (error_buf(word, 1)), else (return 0)
		-> access로 ls or cat + option 처리해보자
	 2-c. input error buf
	 	2-c-1. ls일 때는 word가 알파벳 순, cat은 그냥 순서대로 buf 기입
*/
static int	init_command(t_command **com)
{
	(*com) = (t_command *)malloc(sizeof(t_command));
	if (*com == 0)
		return (1);
	(*com)->order = 0;
	(*com)->word = 0;
	(*com)->redir = 0;
	(*com)->redir_val = 0;
	(*com)->path = 0;
	(*com)->path_err = 0;
	(*com)->builtin = 0;
	(*com)->std_in = 0;
	(*com)->std_out = 1;
	(*com)->std_err = 2;
	(*com)->pipe = 0;
	(*com)->pipe_fd[0] = 0;
	(*com)->pipe_fd[1] = 0;
	(*com)->err_buf = 0;
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
	int			order;

	order = 0;
	init_command(com);
	if (word_cnt(token, *com) || pars_com(token, *com))
		return (1);
	(*com)->order = order;
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
		tmp->order = ++order;
	}
	return (record_builtin(com, *env_list) || record_path(com, *env_list));
}
