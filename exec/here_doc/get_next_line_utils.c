/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:17:00 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/04 16:19:48 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/here_doc.h"

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*strarr;
	size_t	size;
	size_t	i;

	size = ft_strlen(s1) + ft_strlen(s2);
	strarr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (strarr == NULL)
		return (NULL);
	i = 0;
	size = 0;
	while (s1[i] != '\0')
		strarr[size++] = s1[i++];
	strarr[size] = '\0';
	i = 0;
	size = ft_strlen(strarr);
	while (s2[i] != '\0')
		strarr[size++] = s2[i++];
	strarr[size] = '\0';
	return (strarr);
}

void	remove_list(t_list *file_list)
{
	free(file_list->current->back_up);
	file_list->before->next = file_list->current->next;
	if (file_list->current == file_list->tail)
		file_list->tail = file_list->before;
	free(file_list->current);
	file_list->total_fd--;
	if (file_list->total_fd == 0)
		file_list->tail = NULL;
	else
		file_list->current = file_list->before->next;
}
