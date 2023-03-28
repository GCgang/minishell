#include "init.h"

/*
	envp 내용물을 env_list에 담기 위한 내용
	1. init_env : 각각의 환경변수를 등호 기준으로 좌변과 우변으로 분리하여 list에 저장
	2. conv_env : 등호 기준으로 나누어 놓은 내용물을 연결 리스트에 담는 과정
	3. add_exit_status : 무한 반복문 탈출을 위한 기준으로서 env_list에 최선두에 들어감
		3-1. name은 c로 넣고, 추후, 종료 조건을 만족할 시, 안에 있는 val은 exit로 바뀔 예정
*/
static t_env	*conv_env(char *front, char *back)
{
	char	*name;
	char	*val;
	t_env	*node;

	name = ft_strdup(front);
	val = ft_strdup(back);
	node = lstnew_env(name, val);
	return (node);
}

static int	add_exit_status(t_env *node, t_env **env_list)
{
	char	*not;

	not = malloc(sizeof(char) * 2);
	if (!not)
		return (0);
	not[0] = '0';
	not[1] = 0;
	node = lstnew_env(ft_strdup("?"), not);
	node->mean = '?';
	node->status = 0;
	lstadd_front_env(env_list, node);
	return (1);
}

int	init_env(char **envp, t_env **env_list)
{
	int		idx;
	char	*equal;
	t_env	*node;

	idx = 0;
	*env_list = 0;
	while (envp[idx] != 0)
	{
		equal = ft_strchr(envp[idx], '=');
		*equal = 0;
		if (ft_strncmp(envp[idx], "OLDPWD", 7) != 0)
			node = conv_env(envp[idx], equal + 1);
		else
			node = conv_env(envp[idx], 0);
		lstadd_back_env(env_list, node);
		idx++;
	}
	node = conv_env("OLDPWD", 0);
	lstadd_back_env(env_list, node);
	return (add_exit_status(node, env_list));
}
