#include "../include/pars.h"

void	extend_trim_token(t_token *tgt, int num)
{
	t_token *tmp;
	char	*tmp_str;
	char	*str;

	tmp = tgt;
	tmp_str = tmp->val;
	tmp->val = ft_substr(tmp_str, 0, num);
	str = ft_substr(tmp_str, num, ft_strlen(tmp_str));
	free(tmp_str);
	tmp->next = connect_newlst(tmp, str);
}
