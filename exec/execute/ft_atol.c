/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:43:26 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/24 15:54:45 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

long long	ft_atol(const char *str)
{
	long long	result;
	long long	before;
	int			sign;

	result = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str) != 0)
	{
		before = result;
		result *= 10 + (*str - '0');
		if (before > result)
		{
			ft_putstr_fd("Minishell: exit: numeric argument required\n", 2);
			return (255);
		}
		str++;
	}
	return (result * sign);
}
