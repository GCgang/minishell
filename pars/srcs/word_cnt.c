#include "../include/pars.h"

static void	word_del(t_token **token, t_token **now, t_token **before)
{
	if (*token == *now)
	{
		*token = (*now)->next;
		lstdelone_token(*now, &free);
		*now = *token;
	}
	else
	{
		(*before)->next = (*now)->next;
		lstdelone_token(*now, &free);
		*now = (*before)->next;
	}
}

static void	word_array(t_token **token, t_command *com)
{
	int		idx;
	t_token	*now;
	t_token	*before;

	idx = 0;
	before = *token;
	now = *token;
	while (now != 0 && now->type != 'p')
	{
		if (now->type == 'w')
		{
			com->word[idx] = ft_strdup(now->val);
			word_del(token, &now, &before);
			idx++;
		}
		else
		{
			before = now;
			now = now->next;
		}
	}
}

void	word_cnt(t_token **token, t_command *com)
{
	int		cnt;
	t_token	*tmp;

	tmp = *token;
	cnt = 0;
	while (tmp != 0 && tmp->type != 'p')
	{
		if (tmp->type == 'r')
		{
			tmp = tmp->next;
			if (tmp != 0 && tmp->type == 'w')
				tmp->type = 'v';
		}
		else
			cnt++;
		if (tmp != 0)
			tmp = tmp->next;
	}
	com->word = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (com->word == 0)
		return ;
	com->word[cnt] = 0;
	word_array(token, com);
}