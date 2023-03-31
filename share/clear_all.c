/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:06:40 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/31 19:09:48 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	clear_all(t_token **token, t_env **env_list, t_command **com)
{
	lstclear_token(token);
	lstclear_env(env_list);
	lstclear_com(com);
}
