/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clear_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:11:42 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/31 19:11:42 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	lstdelone_env_elem(t_env *before, t_env *now)
{
	t_env	*tmp;

	if (!before || !now)
		return ;
	tmp = now->next;
	if (now->name != 0)
		free((void *)now->name);
	if (now->val != 0)
		free((void *)now->val);
	before->next = tmp;
	free((void *)now);
}

void	lstdelone_env(t_env *lst)
{
	if (!lst)
		return ;
	if (lst->name)
		free((void *)lst->name);
	if (lst->val)
		free((void *)lst->val);
	free(lst);
}

void	lstclear_env(t_env **lst)
{
	t_env	*cur;

	if (!lst)
		return ;
	while (*lst)
	{
		cur = (*lst)->next;
		lstdelone_env(*lst);
		*lst = cur;
	}
	*lst = 0;
}
