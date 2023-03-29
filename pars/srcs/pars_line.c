/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:45:03 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/28 18:57:15 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pars.h"

/*
	readline을 통해 읽은 라인을 파싱하고 실행부로 넘겨주는 내용물
	1. pars_line : token 유무 검사 -> token 제작 -> command 제작 순으로 감
		1-a. chk_have_token : token이 존재하는지 검사
		1-b. make_token : 인용문구, 메타문자, 단어를 기준으로 토큰을 분할
		1-c. trim_token : 각 토큰의 양 끝단 공백, 메타문자 집합에서 불필요한 공백 제거, 각각의 메타문자 별로 토큰 분리
		1-d. pars_extra_token : redirection 토큰 뒤에 위치한 word 토큰 세부 분류(h, v), 토큰에 있는 환경변수 변환, IFS 확인, 토큰 내 문자열 따옴표 제거
*/

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

static void	cpy_meta(char *meta, char *tmp)
{
	int	idx;

	idx = 0;
	while (tmp[idx])
	{
		meta[idx] = tmp[idx];
		idx++;
	}
	meta[idx] = 0;
}

void	pars_line(char *line, t_token **token, t_env **env_list)
{
	char		meta[11];
	t_command	*com;

	*token = 0;
	com = 0;
	cpy_meta(meta, "()<>\t\n |&;");
	if (chk_have_token(line, meta) > 0)
	{
		if (make_token(line, meta, token) || mix_token(token, 0)
			|| rotate_env_token(token, env_list) || mix_token(token, 1)
			|| trim_token(token) || chk_oper_token(*token)
			|| removing_quote(token))
		{
			lstclear_token(token);
			return ;
		}
		if (make_com(token, env_list, &com) == 0)
			test_print_all(env_list, &com);//exec(&com, env_list);
	}
	clear_all(token, 0, &com);
}
