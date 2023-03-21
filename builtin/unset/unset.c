/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <jun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:27:05 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/21 09:33:02 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unset.h"

int	check_unset_syntax(char *variable)
{
	if (ft_isalpha(*variable) == 0 && *variable != '_')
		return (0);
	while (*variable)
	{
		if (ft_isalpha(*variable) == 0\
		|| ft_isdigit(*variable) == 0\
		|| *variable != '_')
			return (0);
		variable++;
	}
	return (1);
}

void	delete_envp(t_env *env_list, char *name)
{
	t_env	*tmp_list;

	tmp_list = env_list->next;
	while (tmp_list != NULL)
	{
		if (ft_strcmp(tmp_list->name, name) == 0)
		{
			//lstdelone_env(env_list, del);
			return ;
		}
		tmp_list = tmp_list->next;
	}
}

void	built_in_unset(t_command **cmd, t_env *env_list)
{
	int	i;

	i = 0;
	while ((*cmd)->word[++i])
	{
		if (check_unset_syntax((*cmd)->word[i]) == 0)
		{
			ft_putstr_fd("not a valid identifier", 2);
			env_list->status = 1;
		}
		else
			delete_envp(env_list, (*cmd)->word[i]);
	}
	return ;
}
