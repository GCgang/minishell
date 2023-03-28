/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:59:21 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/28 18:31:57 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

int	is_built_in(char **word)
{	
	if (word != NULL && word[0] != NULL)
	{
		if (ft_strcmp(word[0], "cd") == 0)
			return (1);
		else if (ft_strcmp(word[0], "echo") == 0)
			return (1);
		else if (ft_strcmp(word[0], "env") == 0)
			return (1);
		else if (ft_strcmp(word[0], "exit") == 0)
			return (1);
		else if (ft_strcmp(word[0], "export") == 0)
			return (1);
		else if (ft_strcmp(word[0], "pwd") == 0)
			return (1);
		else if (ft_strcmp(word[0], "unset") == 0)
			return (1);
	}
	return (0);
}

void	execute_built_in(t_command **cmd, t_env **env_list, int pipe)
{
	if (ft_strcmp((*cmd)->word[0], "cd") == 0)
		built_in_cd(cmd, env_list);
	else if (ft_strcmp((*cmd)->word[0], "echo") == 0)
		built_in_echo(cmd, *env_list);
	else if (ft_strcmp((*cmd)->word[0], "env") == 0)
		built_in_env(cmd, *env_list);
	else if (ft_strcmp((*cmd)->word[0], "exit") == 0)
		built_in_exit(cmd, *env_list);
	else if (ft_strcmp((*cmd)->word[0], "export") == 0)
		built_in_export(cmd, env_list);
	else if (ft_strcmp((*cmd)->word[0], "pwd") == 0)
		built_in_pwd(*env_list);
	else if (ft_strcmp((*cmd)->word[0], "unset") == 0)
		built_in_unset(cmd, *env_list);
	if (pipe == 0)
		return ;
	else if (pipe == 1)
		exit((*env_list)->status);
}

// void	leaks(void)
// {
// 	system("leaks minishell");
// }

// void	redirection(t_command *cmd)
// {
// 	if (ft_strcmp(cmd->redir, "<") == 0)
// 		// next_val == NULL ->  bash: file: No such file or directory (1)
// 	else if (ft_strcmp(cmd->redir, ">") == 0)
// 		// next_val == NULL -> bash: syntax error near unexpected token `newline' (258)
// 	else if (ft_strcmp(cmd->redir, ">>") == 0)
// 		// next_val == NULL -> bash: syntax error near unexpected token `newline' (258)
// 	else	// heredoc ?
// 		return ;
// }

char	*check_cmd(t_command *process)
{
	int		i;
	char	*cmd;
	char	*temp;

	i = -1;
	temp = ft_strjoin("/", process->word[1]);
	printf("temp = %s\n", temp);
	if (access(temp, X_OK) == 0)
		return (temp);
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

void	run_execve(t_command *process)
{
	char	*path_cmd;
	char	**cmds;
	int		i;
	int		j;

	i = 1;
	while (process->word[i] != NULL)
		i++;
	cmds = (char **)malloc(sizeof(char *) * (i));
	j = 0;
	while (j < i)
	{
		cmds[j] = process->word[j + 1];
		j++;
	}
	cmds[i] = NULL;
	path_cmd = check_cmd(process);
	printf("path cmd = %s\n", path_cmd);
	printf("!!!!!!!!!!!!!!!!!!\n\n\n\n\n");
	exit(1);
	if (path_cmd == NULL)
	{
		ft_putstr_fd("Minishell: ", 2);
		ft_putstr_fd(process->word[1], 2);
		ft_putstr_fd(": command not found\n", 2);
		return ;
	}
	execve(path_cmd, cmds, NULL);
}

void	child_process(t_command **process, t_env **env_list)
{
	int		cnt;

	cnt = 0;
	close((*process)->pipe_fd[0]);
	dup2((*process)->pipe_fd[1], 1);
	close((*process)->pipe_fd[1]);
	if (is_built_in((*process)->word))
		execute_built_in(process, env_list, 0);
	if ((*process)->word != NULL && (*process)->word[0] != NULL)
		run_execve(*process);
}

void	parent_process(t_command **cmd)
{
	close((*cmd)->pipe_fd[1]);
	dup2((*cmd)->pipe_fd[0], 0);
	close((*cmd)->pipe_fd[0]);
}

void	execute_binary(t_command **cmd, t_env **env_list)
{
	t_command	*process;
	pid_t		pid;
	int			idx;

	process = *cmd;
	idx = 0;
	while (process != NULL)
	{
		// redirection(process);
		if (pipe((*cmd)->pipe_fd) == -1)
			exit(1);
		pid = fork();
		if (pid == -1)
			exit(1);
		else if (pid == 0)
			child_process(&process, env_list);
		else
			parent_process(cmd);
		process = process->next;
		idx++;
	}
	while (idx--)
		waitpid(-1, NULL, 0);
}

void	exec(t_command **cmd, t_env **env_list)
{
	if ((*cmd)->pipe == 0 && (*cmd) != NULL)
	{
		if (is_built_in((*cmd)->word))
		{
			// STDIN & OUT COPY
			// redirection((*cmd));
			execute_built_in(cmd, env_list, 0);
		}
		else
			execute_binary(cmd, env_list);
	}
	else
	{
		execute_binary(cmd, env_list);
	}
}


/*
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv, char **envp)
{
	char *command[] = {"/bin/ls", "ls", "asdfj", "asdfj", "saddfi", "asdfij", "asdf0", "main.c", "asfdsd", "main.c", 0};
	execve(command[0], command, envp);
	printf("execve failed\n");
	return (0);
}
*/