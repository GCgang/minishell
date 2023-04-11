/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <jun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:14:12 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/11 00:51:36 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef HERE_DOC_H
# define HERE_DOC_H

# include "execute.h"

int		check_here_document(t_command *process);
int		here_document(t_command *process, int idx);
char	*open_here_doc_file(t_command *process, int idx);
int		update_redir(t_command *process, int idx, char *here_doc_file_name);
void	unlink_file(t_command *cmd);

#endif