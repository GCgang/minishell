/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 22:20:38 by hyeoan            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/03/16 22:52:57 by hyeoan           ###   ########.fr       */
=======
/*   Updated: 2023/03/16 22:29:32 by hyeoan           ###   ########.fr       */
>>>>>>> 08698c52d3c56c202fb69a561ab072db58466aa3
/*                                                                            */
/* ************************************************************************** */

#include "../execute.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return (0);
}
