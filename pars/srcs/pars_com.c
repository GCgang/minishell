/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:54 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/21 15:44:54 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pars.h"

int	pars_com(t_token **token, t_env **env_list, t_command *com)
{
	int	status;

	status = pars_oper(token, env_list, com);
	if (status == -1)
	{
		printf("Minishell: %s: No such file or directory\n", com->oper_val);
		change_status(env_list, 1);
	}
	if (status == -2)
	{
		change_status(env_list, 258);
		return (-1);
	}
	if (status == -3)
		change_status(env_list, 1);
	if (status < 0)
		return (-1);
	return (0);
}
