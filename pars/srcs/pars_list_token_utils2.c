#include "../include/pars.h"

void	lstdelone_token_elem(t_token *before, t_token *now, void (*del)(void *))
{
	t_token	*tmp;

	if (!before || !now || !del)
		return ;
	tmp = now->next;
	if (now->val != 0)
		del((void *)now->val);
	before->next = tmp;
	del((void *)now);
}
