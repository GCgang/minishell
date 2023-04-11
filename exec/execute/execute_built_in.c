/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_built_in.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:07:13 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/10 16:13:41 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

int	is_built_in(t_command *process)
{
	if (process->word != NULL && process->word[0] != NULL)
	{
		if (ft_strcmp(process->word[0], "cd") == 0)
			return (1);
		else if (ft_strcmp(process->word[0], "echo") == 0)
			return (1);
		else if (ft_strcmp(process->word[0], "env") == 0)
			return (1);
		else if (ft_strcmp(process->word[0], "exit") == 0)
			return (1);
		else if (ft_strcmp(process->word[0], "export") == 0)
			return (1);
		else if (ft_strcmp(process->word[0], "pwd") == 0)
			return (1);
		else if (ft_strcmp(process->word[0], "unset") == 0)
			return (1);
	}
	return (0);
}

void	only_built_in(t_command **process, t_env **env_list, int cmd_cnt)
{
	parent_std_io_copy((*process));
	if ((*process)->std_in > 0)
	{
		dup2((*process)->std_in, STDIN_FILENO);
		close((*process)->std_in);
	}
	if ((*process)->std_out != 1)
	{
		dup2((*process)->std_out, STDOUT_FILENO);
		close((*process)->std_out);
	}
	execute_built_in(process, env_list, cmd_cnt);
	parent_std_io_reset((*process));
}

void	execute_built_in(t_command **cmd, t_env **env_list, int cmd_cnt)
{
	if (ft_strcmp((*cmd)->word[0], "cd") == 0)
		built_in_cd(cmd, env_list);
	else if (ft_strcmp((*cmd)->word[0], "echo") == 0)
		built_in_echo(cmd);
	else if (ft_strcmp((*cmd)->word[0], "env") == 0)
		built_in_env(cmd, *env_list);
	else if (ft_strcmp((*cmd)->word[0], "exit") == 0)
		built_in_exit(cmd, env_list, cmd_cnt);
	else if (ft_strcmp((*cmd)->word[0], "export") == 0)
		built_in_export(cmd, env_list);
	else if (ft_strcmp((*cmd)->word[0], "pwd") == 0)
		built_in_pwd(*env_list);
	else if (ft_strcmp((*cmd)->word[0], "unset") == 0)
		built_in_unset(cmd, *env_list);
}
