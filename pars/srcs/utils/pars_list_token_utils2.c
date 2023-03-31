/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_list_token_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:53:52 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/29 19:48:49 by jaehjoo          ###   ########.fr       */
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
		free((void *)now->val);
	before->next = tmp;
	free((void *)now);
}
