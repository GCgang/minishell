#include "init.h"

/*
	unset(t_env *env_list, char *name)
	{
		while (env_list->next != 0)
		{
			if (env_list->next->name == name)
			{
				lstdelone_env_elem(env_list, env_list->next, &free);
				return ;
			}
		}
	}
*/

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