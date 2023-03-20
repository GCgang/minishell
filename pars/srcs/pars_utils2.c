#include "../include/pars.h"

void	ft_bzero(void *ptr, size_t num)
{
	size_t			idx;
	unsigned char	*temp;

	idx = 0;
	temp = (unsigned char *)ptr;
	while (idx < num)
	{
		*(temp + idx) = 0;
		idx++;
	}
}

char	*strjoin_append(char const *s1, char const *s2, char c)
{
	char	*temp;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	temp = (char *)malloc(s1_len + s2_len + 2);
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, s1, s1_len + 1);
	temp[s1_len] = c;
	ft_strlcat(temp, s2, s1_len + s2_len + 2);
	return (temp);
}

void	str_tolower(char *str)
{
	int	idx;

	idx = 0;
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
