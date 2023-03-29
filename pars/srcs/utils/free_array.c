/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:37 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/29 19:49:21 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pars.h"

void	free_array(char **arr)
{
	int	idx;

	idx = -1;
	if (arr != 0)
	{
		while (arr[++idx] != 0)
			free(arr[idx]);
		free(arr);
	}
}
