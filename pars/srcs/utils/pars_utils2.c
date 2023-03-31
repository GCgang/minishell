/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:22:53 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/29 19:49:12 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pars.h"

void	ft_bzero(void *ptr, size_t num)
{
	size_t			idx;
	unsigned char	*temp;

	if (!ptr)
		return ;
	idx = 0;
	temp = (unsigned char *)ptr;
	while (idx < num)
	{
		*(temp + idx) = 0;
		idx++;
	}
}

void	str_tolower(char *str)
{
	int	idx;

	idx = 0;
	if (str != 0)
		return ;
	while (str[idx])
	{
		if (65 <= str[idx] && str[idx] <= 90)
			str[idx] += 32;
		idx++;
	}
}

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			idx;
	unsigned char	*temp;

	if (!ptr)
		return (ptr);
	idx = 0;
	temp = (unsigned char *)ptr;
	while (idx < num)
	{
		*(temp + idx) = (unsigned char)value;
		idx++;
	}
	return (ptr);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_size;
	size_t	src_size;

	dest_size = 0;
	src_size = 0;
	if (!dest || !src)
		return (0);
	while (dest[dest_size] && dest_size < size)
		dest_size++;
	while (src[src_size] && (dest_size + src_size + 1 < size))
	{
		dest[dest_size + src_size] = src[src_size];
		src_size++;
	}
	if (dest_size < size)
		dest[dest_size + src_size] = 0;
	return (dest_size + ft_strlen(src));
}
