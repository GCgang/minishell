#include "init.h"

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
