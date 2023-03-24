/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:50 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/23 19:50:36 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pars.h"

/*
	make_token : 인용, 단어, 메타문자 기준으로 토큰을 분할
	1. single_quote : 작은 따옴표로 구성된 문장을 분할
	2. double_quote : 큰 따옴표로 구성된 문장을 분할
	3. sep_none_quote : 인용 부호가 없고 문장의 끝이 아닐 때, 문자 단위로 구분
	4. input_token : 구분된 내용물을 각각의 token으로 분할
	
	개편안
	1. $ 앞에 인용 문구가 존재하지 않는 경우 $는 인용문구를 만나거나 또는 메타문자를 만날 때까지 $ 변수로 취급
	2. $ 바로 뒷 문자가 숫자인 경우, 첫 숫자까지 $변수로 취급
	3. $ 뒤 meta char는 해석 안 함
	4. 위 내용을 고려하여 make_token 시, $변수만 구별하여 제작 필요
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
		else if (now[0] == '$')
			tmp = lstnew_token('e', val);
		else
			tmp = lstnew_token('w', val);
		lstadd_back_token(token, tmp);
		now = 0;
		*len = 0;
	}
}

static char	*quote(char *line, int *idx, int *len, char quote)
{
	if (line[*idx] == quote)
	{
		(*len)++;
		(*idx)++;
		while (line[*idx] != quote && line[*idx] != 0)
		{
			(*len)++;
			(*idx)++;
		}
		(*len)++;
		(*idx)++;
		return (line + *idx - *len);
	}
	return (0);
}

static char	*sep_none_quote(char *line, int *idx, int *len)
{
	if (line[*idx] != 0 && line[*idx] != '\'' && line[*idx] != '\"')
	{
		(*idx)++;
		(*len)++;
	}
	return (line + *idx - *len);
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
		now = quote(line, &idx, &len, '\'');
		input_token(now, token, &len, meta);
		now = quote(line, &idx, &len, '\"');
		input_token(now, token, &len, meta);
		now = sep_none_quote(line, &idx, &len);
		if (len == 1)
			input_token(now, token, &len, meta);
	}
}
