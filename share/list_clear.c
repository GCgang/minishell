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

void	lstdelone_env_elem(t_env *before, t_env *now, void (*del)(void *))
{
	t_env	*tmp;

	if (!before || !now || !del)
		return ;
	tmp = now->next;
	if (now->name != 0)
		del((void *)now->name);
	if (now->val != 0)
		del((void *)now->val);
	before->next = tmp;
	del((void *)now);
}

void	lstdelone_env(t_env *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del((void *)lst->name);
	del((void *)lst->val);
	free(lst);
}

void	lstclear_env(t_env **lst, void (*del)(void *))
{
	t_env	*cur;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		cur = (*lst)->next;
		lstdelone_env(*lst, del);
		*lst = cur;
	}
	*lst = 0;
}
