#include "../include/pars.h"

static int	chk_quote(char *line, int *idx, char quote)
{
	if (line[*idx] == quote)
	{
		(*idx)++;
		while (line[*idx] != quote && line[*idx] != 0)
			(*idx)++;
		if (line[*idx] != quote)
		{
			printf("Error : Don't have closed quote\n");
			return (-42);
		}
		(*idx)++;
		return (1);
	}
	return (0);
}

static int	chk_word_and_oper(char *line, int *idx, char *meta)
{
	if (ft_strchr(meta, line[*idx]) != 0 && line[*idx] != 0)
	{
		while (ft_strchr(meta, line[*idx]) != 0 && line[*idx] != 0)
			(*idx)++;
		return (1);
	}
	else if (line[*idx] != '\'' && line[*idx] != '\"' && line[*idx] != 0)
	{
		while (ft_strchr(meta, line[*idx]) == 0 && line[*idx] != 0
			&& line[*idx] != '\'' && line[*idx] != '\"')
			(*idx)++;
		if ((line[*idx] != '\'' && line[*idx] != '\"') || line[*idx] == 0)
			return (1);
	}
	return (0);
}

int	chk_have_token(char *line, char *meta)
{
	int	idx;

	idx = 0;
	while (line[idx] != 0)
	{
		if (chk_quote(line, &idx, '\'') == -42)
			return (0);
		if (chk_quote(line, &idx, '\"') == -42)
			return (0);
		chk_word_and_oper(line, &idx, meta);
	}
	return (1);
}
