/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <jun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:27:00 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/22 00:23:32 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

int	check_export_syntax(char *cmd)
{
	if (ft_isalpha(*cmd) == 0 && *cmd != '_')
		return (0);
	while (*cmd)
	{
		if (ft_isalpha(*cmd) == 0
			|| ft_isdigit(*cmd) == 0
			|| *cmd != '_')
		{
			return (0);
		}
		cmd++;
	}
	return (1);
}

void	print_export(t_env *env_list)
{
	t_env	*tmp_list;

	tmp_list = env_list;
	while (tmp_list != NULL)
	{
		if (tmp_list->name != NULL && tmp_list->val !=NULL)
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(tmp_list->name, 1);
			ft_putchar_fd('=', 1);
			ft_putstr_fd(tmp_list->val, 1);
			ft_putchar_fd('\n', 1);
		}
		tmp_list = tmp_list->next;
	}
}

void	built_in_export(t_command **cmd, t_env *env_list)
{
	if ((*cmd)->word[1] == NULL)
	{
		//sort_envp()
		print_export(env_list);
		env_list->status = 0;
	}
	else
	{
		while ((*cmd)->word[1])
		{
			if (check_export_syntax((*cmd)->word[1]) == 0)
			{
				ft_putstr_fd("Minishell: export: not a valid identifier\n", 2);
				env_list->status = 1;
			}
			else
			{
				// (*cmd)->word[1] -> split = -> arr[0]:name arr[1]:val
				//init_envp(env_list, name, val);
				env_list->status = 0;
			}
		}
	}
}
