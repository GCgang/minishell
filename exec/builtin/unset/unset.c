/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:27:05 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/12 19:41:52 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unset.h"

void	delete_envp(t_env **env_list, char *name)
{
	t_env	*tmp;
	char	*del_name;

	tmp = *env_list;
	while (tmp->next != NULL)
	{
		del_name = tmp->next->name;
		if (ft_strcmp(del_name, name) == 0)
		{
			lstdelone_env_elem(tmp, tmp->next);
			break ;
		}
		tmp = tmp->next;
	}
	if (ft_strcmp((*env_list)->name, name) == 0)
	{
		tmp = *env_list;
		*env_list = (*env_list)->next;
		lstdelone_env(tmp);
	}
}

void	built_in_unset(t_command **cmd, t_env **env_list)
{
	int	i;

	i = 0;
	while ((*cmd)->word[++i])
		delete_envp(env_list, (*cmd)->word[i]);
	g_exit_status = 0;
}
