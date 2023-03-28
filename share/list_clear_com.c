#include "init.h"

static void	lstdelone_com_redir(t_command *lst)
{
	int	idx;

	if (lst->redir)
	{
		idx = -1;
		while (lst->redir[++idx])
			free(lst->redir[idx]);
		free((void *)lst->redir);
	}
	if (lst->redir_val)
	{
		idx = -1;
		while (lst->redir_val[++idx])
			free(lst->redir_val[idx]);
		free((void *)lst->redir_val);
	}
}

static void	lstdelone_com(t_command *lst)
{
	int		idx;

	if (lst->word)
	{
		idx = -1;
		while (lst->word[++idx])
			free(lst->word[idx]);
		free((void *)lst->word);
	}
	if (lst->path)
	{
		idx = -1;
		while (lst->path[++idx])
			free(lst->path[idx]);
		free((void *)lst->path);
	}
	lstdelone_com_redir(lst);
}

void	lstclear_com(t_command **lst)
{
	t_command	*cur;

	if (!lst)
		return ;
	while (*lst)
	{
		cur = (*lst)->next;
		lstdelone_com(*lst);
		*lst = cur;
	}
}
