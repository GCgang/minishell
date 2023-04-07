/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:45:03 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/06 21:42:41 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pars.h"

void	pars_line(char *line, t_token **token, t_env **env_list, char **envp)
{
	char		spe[12];
	t_command	*com;

	*token = 0;
	com = 0;
	ft_strlcpy(spe, "<> |&\n;(\t)", 12);
	if (chk_close_quote(line) > 0)
	{
		if (make_token(line, spe, token) || mix_token(token, 0)
			|| rotate_env_token(token, env_list) || mix_token(token, 1)
			|| trim_token(token) || chk_oper_token(*token)
			|| removing_quote(token) || !(*token))
		{
			lstclear_token(token);
			return ;
		}
		if (make_com(token, env_list, &com) == 0)
		{
			free(line);
			lstclear_token(token);
			exec(&com, env_list, envp);
		}
	}
	clear_all(token, 0, &com);
}
