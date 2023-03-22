/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:46:21 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/21 15:46:54 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#	ifndef EXPORT_H
# define EXPORT_H

# include "../../include/execute.h"
int		check_export_syntax(char *cmd);
void	print_export(t_env *env_list);

void	built_in_export(t_command **cmd, t_env *env_list);

#endif