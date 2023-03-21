#include "../include/pars.h"

/*
	path 문제점
	1. path가 있는 경우, '/' -> access -> X : no such file or directory, '/'가 없으면 : command not found
	2. path가 없으면 '/' 경로로 인식을 못함 : no such file or directory, builtin은 path와 상관 없이 인식

	개선 예정
	1. path는 보류
	2. builtin은 개별로 해서 export, unset 제외 소문자로 바꾸기
*/

static char	chk_extend_builtin(t_command *com, char *tgt)
{
	if (ft_strncmp(tgt, "export", 7) == 0
		|| ft_strncmp(tgt, "unset", 6) == 0)
	{
		if (ft_strncmp(com->word[0], "export", 7) == 0)
			return ('x');
		else if (ft_strncmp(com->word[0], "unset", 6 == 0))
			return ('u');
	}
	return (0);
}

static int	builtin(t_command *com, char *tgt)
{
	if (com->word != 0)
	{
		str_tolower(tgt);
		if (ft_strncmp(tgt, "echo", 5) == 0)
			com->builtin = 'e';
		else if (ft_strncmp(tgt, "cd", 3) == 0)
			com->builtin = 'c';
		else if (ft_strncmp(tgt, "pwd", 4) == 0)
			com->builtin = 'p';
		else if (ft_strncmp(tgt, "env", 4) == 0)
			com->builtin = 'n';
		else if (ft_strncmp(tgt, "exit", 5) == 0)
			com->builtin = 'i';
		else
			com->builtin = chk_extend_builtin(com, tgt);
	}
	if (ft_strchr("ecpni", com->builtin) != 0)
		str_tolower(com->word[0]);
	if (ft_strchr("ecpxuni", com->builtin) != 0)
		return (1);
	return (0);
}

void	record_extra(t_command **com, t_env *env_list)
{
	char	*tmp;

	tmp = ft_strdup((*com)->word[0]);
	builtin((*com), tmp);
	free(tmp);
	if ((*com)->next != 0)
		record_extra(&((*com)->next), env_list);
}
