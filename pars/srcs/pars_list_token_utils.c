#include "../include/pars.h"

static t_token	*lstlast_token(t_token *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	lstadd_back_token(t_token **lst, t_token *new)
{
	t_token	*last;

	if (!new || !lst)
		return ;
	if (*lst)
	{
		last = lstlast_token(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

void	lstclear_token(t_token **lst, void (*del)(void *))
{
	t_token	*cur;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		cur = (*lst)->next;
		lstdelone_token(*lst, del);
		*lst = cur;
	}
	*lst = 0;
}

void	lstdelone_token(t_token *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->val);
	del(lst->quote);
	free(lst);
}

t_token	*lstnew_token(char type, char *val)
{
	t_token	*tmp;

	tmp = (t_token *)malloc(sizeof(t_token));
	if (!tmp)
		return (0);
	tmp->type = type;
	tmp->val = val;
	tmp->quote = (char *)malloc(sizeof(char) * (ft_strlen(val) + 1));
	ft_bzero(tmp->quote, ft_strlen(val) + 1);
	if (!(tmp->quote))
		return (0);
	tmp->quote[ft_strlen(val)] = 0;
	tmp->next = 0;
	return (tmp);
}