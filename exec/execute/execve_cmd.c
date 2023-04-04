/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:54:02 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/04 19:28:37 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

char	*check_cmd(t_command *process, t_env **env_list)
{
	int		i;
	char	*cmd;
	char	*temp;

	if (access(process->word[0], X_OK) == 0)
		return (process->word[0]);
	if (get_value(*env_list, "PATH") == NULL)
		return (NULL);
	if (ft_strchr(process->word[0], '/'))
		return (NULL);
	temp = ft_strjoin("/", process->word[0]);
	i = -1;
	while (process->path[++i] != NULL)
	{
		cmd = ft_strjoin(process->path[i], temp);
		if (access(cmd, X_OK) == 0)
			return (cmd);
		free(cmd);
	}
	free(temp);
	return (NULL);
}

void	run_execve(t_command *process, t_env **env_list, char **envp)
{
	char	*path_cmd;
	int		ret;

	path_cmd = check_cmd(process, env_list);
	ret = execve(path_cmd, process->word, envp);
	if (ret == -1)
	{
		if (ft_strchr(process->word[0], '/') != NULL || get_value(*env_list, "PATH") == NULL)
		{
			ft_putstr_fd("Minishell: ", 2);
			ft_putstr_fd(process->word[0], 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			g_exit_status = 127;
		}
		else
		{
			ft_putstr_fd("Minishell: ", 2);
			ft_putstr_fd(process->word[0], 2);
			ft_putstr_fd(": command not found\n", 2);
			g_exit_status = 127;
		}
	}
}
