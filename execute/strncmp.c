/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:18:05 by hyeoan            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/03/16 22:52:59 by hyeoan           ###   ########.fr       */
=======
/*   Updated: 2023/03/16 22:25:54 by hyeoan           ###   ########.fr       */
>>>>>>> 08698c52d3c56c202fb69a561ab072db58466aa3
/*                                                                            */
/* ************************************************************************** */

#include "../execute.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((*s1 != '\0' && *s1 == *s2) && i < n)
	{
		++s1;
		++s2;
		++i;
	}
	if (i == n)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}