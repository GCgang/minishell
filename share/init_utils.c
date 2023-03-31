/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:11:34 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/31 19:11:34 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

size_t	ft_strlen(const char *str)
{
	size_t	idx;

	idx = 0;
	if (!str)
		return (0);
	while (str[idx])
		idx++;
	return (idx);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	if ((!*s1 && !*s2) || n == 0)
		return (0);
	while (s1[idx] && s1[idx] == s2[idx] && idx < n - 1)
		idx++;
	return (*((unsigned char *)(s1 + idx)) - *((unsigned char *)(s2 + idx)));
}

char	*ft_strchr(const char *str, int c)
{
	size_t			idx;
	unsigned char	tgt;

	idx = 0;
	tgt = (unsigned char)c;
	if (!str)
		return (0);
	while (str[idx])
	{
		if (str[idx] == tgt)
			return ((char *)str + idx);
		idx++;
	}
	if (str[idx] == tgt)
		return ((char *)str + idx);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		idx;
	int		len;

	idx = 0;
	len = 0;
	if (!s1)
		return (0);
	while (s1[len])
		len++;
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (0);
	while (s1[idx])
	{
		dest[idx] = s1[idx];
		idx++;
	}
	dest[idx] = 0;
	return (dest);
}
