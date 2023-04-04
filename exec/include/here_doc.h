/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:14:12 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/04 16:22:12 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef HERE_DOC_H
# define HERE_DOC_H

# include "execute.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_node
{
	int				fd;
	char			*back_up;
	struct s_node	*next;
}	t_file_node;

typedef struct s_list
{
	t_file_node	*tail;
	t_file_node	*before;
	t_file_node	*current;
	size_t		total_fd;
}	t_list;

void	check_here_document(t_command *process);
void	here_document(t_command *process, int idx);
char	*get_next_line(int fd);
int		find_node(t_list *file_list, int fd);
int		add_node(t_list *file_list, int fd);
char	*read_file(t_list *file_list, char *buf);
char	*make_line(t_list *file_list);
char	*gnl_strjoin(char *s1, char *s2);
void	remove_list(t_list *file_list);

#endif