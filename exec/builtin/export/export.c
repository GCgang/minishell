/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <jun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:27:00 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/03 00:58:27 by jun              ###   ########.fr       */
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

void	print_export(t_command **cmd, t_env *env_list)
{
	t_env	*tmp_list;
	(void)cmd;//
	tmp_list = sort_export(env_list);
	tmp_list = env_list;
	while (tmp_list != NULL)
	{
		if (tmp_list->name != NULL)
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(tmp_list->name, 1);
			// ft_putstr_fd("declare -x ", (*cmd)->std_out);
			// ft_putstr_fd(tmp_list->name, (*cmd)->std_out);
			if (tmp_list->val != NULL)
			{
				ft_putchar_fd('=', 1);
				ft_putchar_fd('"', 1);
				ft_putstr_fd(tmp_list->val, 1);
				ft_putchar_fd('"', 1);
				// ft_putchar_fd('=', (*cmd)->std_out);
				// ft_putchar_fd('"', (*cmd)->std_out);
				// ft_putstr_fd(tmp_list->val, (*cmd)->std_out);
				// ft_putchar_fd('"', (*cmd)->std_out);
			}
			ft_putchar_fd('\n', 1);
			// ft_putchar_fd('\n', (*cmd)->std_out);
		}
		tmp_list = tmp_list->next;
	}
	free(tmp_list);
}

t_env	*sort_export(t_env *env_list)
{
	t_env	*n_list;
	t_env	*result;
	char	*name;
	char	*val;

	result = env_list;
	while (env_list != NULL)
	{
		n_list = env_list->next;
		while (n_list != NULL)
		{
			if (ft_strcmp(env_list->name, n_list->name) > 0)
			{
				name = n_list->name;
				val = n_list->val;
				n_list->name = env_list->name;
				n_list->val = env_list->val;
				env_list->name = name;
				env_list->val = val;
			}
			n_list = n_list->next;
		}
		env_list = env_list->next;
	}
	return (result);
}

void	update_export_envp(t_env **env_list, char *name)
{
	char	*new_name;
	char	*new_value;
	char	*equal;

	equal = ft_strchr(name, '=');
	new_name = ft_substr(name, 0, (ft_strlen(name) - ft_strlen(equal)));
	if (equal == NULL)
	{
		if (get_value(*env_list, new_name) == NULL)
			init_envp(env_list, name, NULL);
		free(new_name);
		return ;
	}
	else
	{
		new_value = ft_substr(equal, 1, ft_strlen(equal) - 1);
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
		print_export(cmd, (*env_list)->next);
		g_exit_status = 0;
	}
	else
	{
		while ((*cmd)->word[++i])
		{
			if (check_export_syntax((*cmd)->word[i]) == 0)
			{
				ft_putstr_fd("Minishell: export: not a valid identifier\n", 2);
				g_exit_status = 1;
			}
			else
			{
				update_export_envp(env_list, (*cmd)->word[i]);
				g_exit_status = 0;
			}
		}
	}
}
