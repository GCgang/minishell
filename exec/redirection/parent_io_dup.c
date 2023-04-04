/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_io_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:52:49 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/04 14:59:54 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/redirection.h"

void	parent_std_io_copy(t_command *cmd)
{
	cmd->std_in_dup = dup(STDIN_FILENO);
	cmd->std_out_dup = dup(STDOUT_FILENO);
}

void	parent_std_io_reset(t_command *cmd)
{
	dup2(cmd->std_in_dup, STDIN_FILENO);
	close(cmd->std_in_dup);
	dup2(cmd->std_out_dup, STDOUT_FILENO);
	close(cmd->std_out_dup);
}
