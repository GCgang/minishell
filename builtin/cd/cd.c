/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:26:49 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/17 20:45:22 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

void	built_in_cd(void)
{
	char	*buf;
	char	*dir;
	char	*cmd;

	buf = NULL;
	//ex
	cmd = "/Users/hyeoan/minishell";
	// if (ft_strcmp(cmd, ".") == 0)
	// 	change_cur_dir();
	// else if ((ft_strcmp(cmd, "..") == 0) || (ft_strcmp(cmd, "/") == 0))
	// 	change_parent_dir();
	// else if ((ft_strcmp(cmd, "cd") == 0) || (ft_strcmp(cmd, "~") == 0))
	// 	change_home_dir();
	// else if (access(cmd, F_OK) == 0)
	// 	change_abs_rel_dir();
	/*
		getcwd()
		chdir()
		getenv()
			cd
			getenv(PWD)
			getenv(OLDPWD)
			swap
	*/
	return ;
}
