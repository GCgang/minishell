/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:11:22 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/07 17:24:09 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int	err_msg(char *str, int newline, int **fr)
{
	write(2, str, ft_strlen(str));
	if (newline)
		write(2, "\n", 1);
	if (fr && *fr)
		free(*fr);
	return (1);
}
