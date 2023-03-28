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
	if (lst->name)
		del((void *)lst->name);
	if (lst->val)
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

static void	lstdelone_com(t_command *lst, void (*del)(void *))
{
	int		idx;

	if (lst->word)
	{
		idx = -1;
		while (lst->word[++idx])
			del(lst->word[idx]);
		del((void *)lst->word);
	}
	if (lst->path)
	{
		idx = -1;
		while (lst->path[++idx])
			del(lst->path[idx]);
		del((void *)lst->path);
	}
	if (lst->oper)
		del((void *)lst->oper);
	if (lst->oper_val)
		del((void *)lst->oper_val);
	if (lst->err_buf)
		del((void *)lst->err_buf);
}

void	lstclear_com(t_command **lst, void (*del)(void *))
{
	t_command	*cur;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		cur = (*lst)->next;
		lstdelone_com(*lst, del);
		*lst = cur;
	}
}
