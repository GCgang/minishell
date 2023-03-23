/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:50 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/22 16:37:50 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pars.h"

/*
	make_token : 인용, 단어, 메타문자 기준으로 토큰을 분할
	1. single_quote : 작은 따옴표로 구성된 문장을 분할
	2. double_quote : 큰 따옴표로 구성된 문장을 분할
	3. word_and_oper : 메타문자로 구성된 문장 또는 단어만으로 구성된 문장으로 분할
	4. input_token : 1 ~ 3 과정을 거친 문장을 직접 분할하여 토큰으로 넣는다.
		4-a. 메타문자인 경우, token->type = t, 아닌 경우, token->type = w
	
	개편안
	1. single_quote, double_quote, word, oper로 분할
	2. token 중, w에서 w로 이어지는 경우 둘은 융합하고 나머지 하나 del
	3. 
*/
static void	input_token(char *now, t_token **token, int *len, char *meta)
{
	t_token	*tmp;
	char	*val;

	if (now != 0 && *len != 0)
	{
		val = (char *)malloc(sizeof(char) * (*len + 1));
		ft_strlcpy(val, now, *len + 1);
		if (ft_strchr(meta, now[0]) != 0)
			tmp = lstnew_token('t', val);
		else
			tmp = lstnew_token('w', val);
		lstadd_back_token(token, tmp);
		now = 0;
		*len = 0;
	}
}

static char	*single_quote(char *line, int *idx, int *len, char *meta)
{
	if (line[*idx] == '\'')
	{
		(*len)++;
		(*idx)++;
		while (line[*idx] != '\'' && line[*idx] != 0)
		{
			(*len)++;
			(*idx)++;
		}
		(*len)++;
		(*idx)++;
		if (line[*idx] == 0 || ft_strchr(meta, line[*idx]) != 0)
			return (line + *idx - *len);
	}
	return (0);
}

static char	*double_quote(char *line, int *idx, int *len, char *meta)
{
	if (line[*idx] == '\"')
	{
		(*len)++;
		(*idx)++;
		while (line[*idx] != '\"' && line[*idx] != 0)
		{
			(*len)++;
			(*idx)++;
		}
		(*len)++;
		(*idx)++;
		if (line[*idx] == 0 || ft_strchr(meta, line[*idx]) != 0)
			return (line + *idx - *len);
	}
	return (0);
}

static char	*word_and_oper(char *line, int *idx, int *len, char *meta)
{
	if (ft_strchr(meta, line[*idx]) != 0 && line[*idx] != 0)
	{
		while (ft_strchr(meta, line[*idx]) != 0 && line[*idx] != 0)
		{
			(*len)++;
			(*idx)++;
		}
		return (line + *idx - *len);
	}
	else if (line[*idx] != '\'' && line[*idx] != '\"' && line[*idx] != 0)
	{
		while (ft_strchr(meta, line[*idx]) == 0 && line[*idx] != 0
			&& line[*idx] != '\'' && line[*idx] != '\"')
		{
			(*len)++;
			(*idx)++;
		}
		if ((line[*idx] != '\'' && line[*idx] != '\"') || line[*idx] != 0)
			return (line + *idx - *len);
	}
	return (0);
}

void	make_token(char *line, char *meta, t_token **token)
{
	int		idx;
	int		len;
	char	*now;

	idx = 0;
	len = 0;
	now = 0;
	while (line[idx] != 0)
	{
		now = single_quote(line, &idx, &len, meta);
		input_token(now, token, &len, meta);
		now = double_quote(line, &idx, &len, meta);
		input_token(now, token, &len, meta);
		now = word_and_oper(line, &idx, &len, meta);
		input_token(now, token, &len, meta);
	}
}
