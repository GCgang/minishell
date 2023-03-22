/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:26:56 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/22 18:28:19 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	built_in_env(t_command **cmd, t_env *env_list)
{
	t_env	*tmp_list;

	if ((*cmd)->word[1] == NULL)
	{
		tmp_list = env_list->next;
		while (tmp_list != NULL)
		{
			if (tmp_list->name != NULL && tmp_list->val != NULL)
			{
				ft_putstr_fd(tmp_list->name, 1);
				ft_putchar_fd('=', 1);
				ft_putstr_fd(tmp_list->val, 1);
				ft_putchar_fd('\n', 1);
			}
			tmp_list = tmp_list->next;
		}
	}
	else
	{
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd((*cmd)->word[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		env_list->status = 127;
	}
}
