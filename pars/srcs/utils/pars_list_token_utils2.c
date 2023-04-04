/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_list_token_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:53:52 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/04 13:04:16 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pars.h"

void	lstdelone_token_elem(t_token *before, t_token *now)
{
	t_token	*tmp;

	if (!before || !now)
		return ;
	tmp = now->next;
	if (now->val != 0)
		free(now->val);
	before->next = tmp;
	free(now);
}
