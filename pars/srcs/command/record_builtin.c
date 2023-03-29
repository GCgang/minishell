/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:50:28 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/29 19:56:55 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pars.h"

static char	*ft_strchr_null(const char *str, int c)
{
	size_t			idx;
	unsigned char	tgt;

	idx = 0;
	tgt = (unsigned char)c;
	while (str[idx])
	{
		if (str[idx] == tgt)
			return ((char *)str + idx);
		idx++;
	}
	return (0);
}

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
	if (ft_strchr_null("ecpni", com->builtin) != 0)
		str_tolower(com->word[0]);
	if (ft_strchr_null("ecpxuni", com->builtin) != 0)
		return (1);
	return (0);
}

int	record_builtin(t_command **com, t_env *env_list)
{
	char	*tmp;

	if ((*com)->word != 0)
	{
		tmp = ft_strdup((*com)->word[0]);
		if (tmp == 0)
			return (err_msg("Error : Malloc failed(word_cnt)"));
		builtin((*com), tmp);
		free(tmp);
	}
	if ((*com)->next != 0)
		record_builtin(&((*com)->next), env_list);
	return (0);
}

int	record_path(t_command **com, t_env *env_list)
{
	t_env	*tmp;
	char	**tmp_path;

	tmp = env_list;
	while (tmp)
	{
		if (ft_strncmp(tmp->name, "PATH", 5) == 0)
		{
			tmp_path = ft_split(tmp->val, ':');
			if (tmp_path == 0)
				return (err_msg("Error : Malloc failed(record_path)"));
			if ((*com)->path != 0)
				free((*com)->path);
			(*com)->path = tmp_path;
		}
		tmp = tmp->next;
	}
	return (0);
}
