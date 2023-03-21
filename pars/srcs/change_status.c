/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_status.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:15 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/21 15:44:15 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pars.h"

static int	ft_num_cnt(int n)
{
	int	cnt;

	cnt = 0;
	if (n <= 0)
		cnt++;
	while (n != 0)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}

static void	ft_strswap(char *num_str)
{
	int		len;
	int		idx;
	char	temp;

	len = ft_strlen(num_str);
	idx = 0;
	while (idx < len / 2)
	{
		temp = num_str[idx];
		num_str[idx] = num_str[len - 1 - idx];
		num_str[len - 1 - idx] = temp;
		idx++;
	}
}

static void	ft_insert_num(char *num_str, int n)
{
	long	cpy_n;
	int		idx;

	idx = 0;
	cpy_n = n;
	if (cpy_n < 0)
		cpy_n *= -1;
	if (!cpy_n)
		num_str[idx++] = 48;
	while (cpy_n != 0)
	{
		num_str[idx++] = (cpy_n % 10) + 48;
		cpy_n /= 10;
	}
	if (n < 0)
		num_str[idx++] = '-';
	num_str[idx] = 0;
}

static char	*ft_itoa(int n)
{
	char	*num_str;

	num_str = (char *)malloc(ft_num_cnt(n) + 1);
	if (!num_str)
		return (NULL);
	ft_insert_num(num_str, n);
	ft_strswap(num_str);
	return (num_str);
}

void	change_status(t_env **env_list, int status)
{
	t_env	*tmp;

	tmp = *env_list;
	while (tmp->mean != '?')
		tmp = tmp->next;
	tmp->status = status;
	if (tmp->val != 0)
		free(tmp->val);
	tmp->val = ft_itoa(tmp->status);
}
