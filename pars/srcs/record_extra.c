#include "../include/pars.h"

static char	**find_and_split(t_env *env_list)
{
	char	**path;

	path = 0;
	while (env_list != 0)
	{
		if (ft_strncmp(env_list->name, "PATH", 5) == 0)
		{
			path = ft_split(env_list->val, ':');
			break ;
		}
		env_list = env_list->next;
	}
	return (path);
}

static char	*find_path(t_env *env_list, char *com)
{
	char	**path;
	char	*val;
	int		idx;

	idx = -1;
	path = find_and_split(env_list);
	while (path != 0 && path[++idx] != 0)
	{
		val = strjoin_append(path[idx], com, '/');
		if (access(val, F_OK | X_OK) == 0)
		{
			free_array(path);
			return (val);
		}
		free(val);
	}
	if (path != 0)
		free_array(path);
	return (0);
}

static int	builtin(t_command *com)
{
	if (com->word != 0)
	{
		if (ft_strncmp(com->word[0], "echo", 5) == 0)
			com->builtin = 'e';
		else if (ft_strncmp(com->word[0], "cd", 3) == 0)
			com->builtin = 'c';
		else if (ft_strncmp(com->word[0], "pwd", 4) == 0)
			com->builtin = 'p';
		else if (ft_strncmp(com->word[0], "export", 7) == 0)
			com->builtin = 'x';
		else if (ft_strncmp(com->word[0], "unset", 6) == 0)
			com->builtin = 'u';
		else if (ft_strncmp(com->word[0], "env", 4) == 0)
			com->builtin = 'n';
		else if (ft_strncmp(com->word[0], "exit", 5) == 0)
			com->builtin = 'i';
	}
	if (ft_strchr("ecpxuni", com->builtin) != 0)
		return (1);
	return (0);
}

void	record_extra(t_command *com, t_env *env_list)
{
	char	*path;

	path = 0;
	if (com->word == 0 || com->word[0] == 0)
	{
		com->path = 0;
		return ;
	}
	str_tolower(com->word[0]);
	if ((builtin(com) == 1) || ft_strchr(com->word[0], '/' != 0))
		path = ft_strdup(com->word[0]);
	else
	{
		path = find_path(env_list, com->word[0]);
		if (path != 0)
		{
			free(com->word[0]);
			com->word[0] = ft_strdup(path);
		}
	}
	if (path == 0)
		com->path_err = 1;
	com->path = path;
}
