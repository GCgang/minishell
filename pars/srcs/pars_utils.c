/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:45:25 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/24 14:26:25 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pars.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	idx;
	size_t	src_len;

	src_len = 0;
	if (!dest || !src)
		return (0);
	while (src[src_len])
		src_len++;
	if (!size || !dest)
		return (src_len);
	idx = 0;
	while (idx < size - 1 && *(src + idx))
	{
		*(dest + idx) = *(src + idx);
		idx++;
	}
	*(dest + idx) = 0;
	return (src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	temp = (char *)malloc(s1_len + s2_len + 1);
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, s1, s1_len + 1);
	ft_strlcat(temp, s2, s1_len + s2_len + 1);
	return (temp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	str_len;
	size_t	idx;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	idx = 0;
	if (start < str_len && len < str_len)
		temp = (char *)malloc(len + 1);
	else if (start < str_len && len >= str_len)
		temp = (char *)malloc(str_len + 1);
	else
		temp = (char *)malloc(1);
	if (!temp)
		return (NULL);
	if (start < str_len)
	{
		while (s[start] && idx < len)
			temp[idx++] = s[start++];
	}
	temp[idx] = 0;
	return (temp);
}
