/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <jun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:27:05 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/23 02:16:06 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unset.h"

int	check_unset_syntax(char *variable)
{
	if (ft_isalpha(*variable) == 0 && *variable != '_')
		return (0);
	while (*variable)
	{
		if ((ft_isalpha(*variable) == 0 && ft_isdigit(*variable) == 0) && *variable != '_')			return (0);
			variable++;
	}
	return (1);
}

void	delete_envp(t_env *env_list, char *name)
{
	t_env	*before;
	char	*del_name;

	while (env_list->next != NULL)
	{
		before = env_list;
		del_name = env_list->next->name;
		if (ft_strcmp(del_name, name) == 0)
			lstdelone_env_elem(before, env_list, &free);
		break ;
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
