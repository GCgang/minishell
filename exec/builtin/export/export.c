/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:27:00 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/23 16:12:48 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

int	check_export_syntax(char *cmd)
{
	if (ft_isalpha(*cmd) == 0 && *cmd != '_')
		return (0);
	while (*cmd && *cmd != '=')
	{
		if ((ft_isalpha(*cmd) == 0 && ft_isdigit(*cmd) == 0) && *cmd != '_')
			return (0);
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
		if (tmp_list->name != NULL )
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(tmp_list->name, 1);
			if (tmp_list->val != NULL)
			{
				ft_putchar_fd('=', 1);
				ft_putchar_fd('"', 1);
				ft_putstr_fd(tmp_list->val, 1);
				ft_putchar_fd('"', 1);
			}
			ft_putchar_fd('\n', 1);
		}
		tmp_list = tmp_list->next;
	}
}

void	sort_export()
{
	//sorting
}

void	update_export_envp(t_env **env_list, char *name)
{
	char	*new_name;
	char	*new_value;
	char	*equl;

	equl = ft_strchr(name, '=');
	new_name = ft_substr(name, 0, (ft_strlen(name) - ft_strlen(equl)));
	if (equl == NULL)
	{
		if (get_value(*env_list, new_name) == NULL)
			init_envp(env_list, name, NULL);
		free(new_name);
		return ;
	}
	else
	{
		new_value = ft_substr(equl, 1, ft_strlen(equl) - 1);
		if (new_value == NULL)
			new_value = "";
		init_envp(env_list, new_name, new_value);
		free(new_value);
	}
	free(new_name);
}

void	built_in_export(t_command **cmd, t_env **env_list)
{
	int		i;

	i = 0;
	if ((*cmd)->word[1] == NULL)
	{
		//sort_export()
		print_export((*env_list)->next);
		(*env_list)->status = 0;
	}
	else
	{
		while ((*cmd)->word[++i])
		{
			if (check_export_syntax((*cmd)->word[i]) == 0)
			{
				ft_putstr_fd("Minishell: export: not a valid identifier\n", 2);
				(*env_list)->status = 1;
			}
			else
			{
				update_export_envp(env_list, (*cmd)->word[i]);
				(*env_list)->status = 0;
			}
		}
	}
	print_export((*env_list)->next);
}