#include "init.h"

void	lstdelone_env_elem(t_env *before, t_env *now, void (*del)(void *))
{
	t_env	*tmp;

	if (!before || !now || !del)
		return ;
	tmp = now->next;
	del((void *)now->name);
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
