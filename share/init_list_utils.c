#include "init.h"

void	lstadd_front_env(t_env **lst, t_env *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_env	*lstnew_env(char *name, char *val)
{
	t_env	*temp;

	temp = (t_env *)malloc(sizeof(t_env));
	if (!temp)
		return (NULL);
	temp->name = name;
	temp->val = val;
	temp->mean = 'e';
	temp->status = 1;
	temp->next = 0;
	return (temp);
}

static t_env	*lstlast_env(t_env *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	lstadd_back_env(t_env **lst, t_env *new)
{
	t_env	*last;

	if (!new || !lst)
		return ;
	if (*lst)
	{
		last = lstlast_env(*lst);
		last->next = new;
	}
	else
		*lst = new;
}
