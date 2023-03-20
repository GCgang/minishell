/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <jun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:26:56 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/21 01:33:52 by jun              ###   ########.fr       */
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
		ft_putstr_fd("env: No such file or directory", 2);
		env_list->status = 127;
	}

}
