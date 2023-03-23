/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:27:05 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/23 16:32:23 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unset.h"

int	check_unset_syntax(char *variable)
{
	if (ft_isalpha(*variable) == 0 && *variable != '_')
		return (0);
	while (*variable)
	{
		if ((ft_isalpha(*variable) == 0 && ft_isdigit(*variable) == 0) && *variable != '_')
			return (0);
		variable++;
	}
	return (1);
}

void	delete_envp(t_env *env_list, char *name)
{
	t_env	*tmp;
	char	*del_name;

	tmp = env_list;
	while (tmp->next != NULL)
	{
		del_name = tmp->next->name;
		if (ft_strcmp(del_name, name) == 0)
		{
			lstdelone_env_elem(tmp, tmp->next, &free);
			break ;
		}
		tmp = tmp->next;
	}
}

void	built_in_unset(t_command **cmd, t_env *env_list)
{
	int	i;

	i = 0;
	env_list->status = 0;
	while ((*cmd)->word[++i])
	{
		if (check_unset_syntax((*cmd)->word[i]) == 0)
		{
			ft_putstr_fd("Minishell: unset: not a valid identifier\n", 2);
			env_list->status = 1;
		}
		else
			delete_envp(env_list, (*cmd)->word[i]);
	}
	return ;
}
