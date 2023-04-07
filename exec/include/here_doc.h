/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:14:12 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/07 16:50:31 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef HERE_DOC_H
# define HERE_DOC_H

# include "execute.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
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

int		check_here_document(t_command *process);
int		here_document(t_command *process, int idx);
char	*open_here_doc_file(t_command *process, int idx);
int		update_redir(t_command *process, int idx, char *here_doc_file_name);
void	unlink_file(t_command *cmd);

#endif