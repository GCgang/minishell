/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_split_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:45:21 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/29 19:49:00 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pars.h"

static char	**ft_free(char **split_wd, size_t cur)
{
	size_t	idx;

	idx = 0;
	while (idx < cur)
	{
		free(split_wd[idx]);
		idx++;
	}
	free(split_wd);
	return (NULL);
}

static char	*ft_strccpy(char const *s, char c)
{
	char	*temp;
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	temp = (char *)malloc(len + 1);
	if (!temp)
		return (NULL);
	len = 0;
	while (s[len] && s[len] != c)
	{
		temp[len] = s[len];
		len++;
	}
	temp[len] = 0;
	return (temp);
}

static size_t	ft_wdcnt(char const *s, char c)
{
	size_t	idx;
	size_t	cnt;

	idx = 0;
	cnt = 0;
	while (s[idx])
	{
		while (s[idx] && s[idx] == c)
			idx++;
		if (s[idx] && s[idx] != c)
			cnt++;
		while (s[idx] && s[idx] != c)
			idx++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**split_wd;
	size_t	cur;

	if (!s)
		return (NULL);
	split_wd = (char **)malloc(sizeof(char *) * (ft_wdcnt(s, c) + 1));
	if (!split_wd)
		return (ft_free(split_wd, 0));
	cur = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			split_wd[cur] = ft_strccpy(s, c);
			if (!split_wd[cur])
				return (ft_free(split_wd, cur));
			cur++;
			while (*s && *s != c)
				s++;
		}
	}
	split_wd[cur] = NULL;
	return (split_wd);
}
