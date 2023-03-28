#include "../include/pars.h"

void	lstdelone_token_elem(t_token *before, t_token *now)
{
	t_token	*tmp;

	if (!before || !now)
		return ;
	tmp = now->next;
	if (now->val != 0)
		free((void *)now->val);
	before->next = tmp;
	free((void *)now);
}
