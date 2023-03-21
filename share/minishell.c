/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:57:22 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/21 18:57:22 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

/*
	1. main
		a. init_chk : 최초 signal handling 설정, envp를 env_list에 넣기, ascii art 그려넣기 수행
		b. pars_line : readline을 통해 받은 내용물을 파싱하고 실행하는 과정 진입
		c. chk_res : 미니쉘 종료 여부를 확인하기 위한 함수.
	2. init_chk
		a. ac > 1 : 사용자 입력 인자 검사. 들어올 인자가 없으므로 인자가 있으면 오류 처리.
		b. init_signal : 과제에서 요구하는 ctrl 관련 시그널을 핸들링하기 위한 함수
		c. conv_envp : 환경변수들을 사용하기 편하게 연결 리스트로 변환하기 위한 파싱 함수
		d. introduce : 처음에 보기 좋게 만들어 줄 아스키 아트
	3. chk_res : env_list에서 exit가 나왔는 지 확인. exit가 있는 경우 종료
*/
static void	introduce(void)
{
}

static int	chk_res(t_env *env_list, int *res)
{
	while (env_list->mean != 'c')
		env_list = env_list->next;
	if (env_list->val != 0)
	{
		if (!(ft_strncmp(env_list->val, "exit", 5)))
		{
			*res = env_list->status;
			return (1);
		}
	}
	return (0);
}

static int	init_chk(int ac, char **envp, t_env **env_list)
{
	if (ac > 1)
	{
		printf("Error : You don't need to insert argument\n");
		return (1);
	}
	init_signal();
	init_env(envp, env_list);
	introduce();
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	char	*line;
	t_env	*env_list;
	t_token	*tokens;
	int		res;

	(void)av;
	if (init_chk(ac, envp, &env_list) != 0)
		return (0);
	while (1)
	{
		line = readline("Minishell$ ");
		if (!line)
		{
			printf("exit\n");
			return (0);
		}
		if (*line != 0)
			add_history(line);
		pars_line(line, &tokens, &env_list);
		free(line);
		if (chk_res(env_list, &res) != 0)
			break ;
	}
	lstclear_env(&env_list, &free);
	return (res);
}
