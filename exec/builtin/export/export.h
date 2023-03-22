/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <jun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:46:21 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/23 02:13:01 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#	ifndef EXPORT_H
# define EXPORT_H

# include "../../include/execute.h"
int		check_export_syntax(char *cmd);
void	print_export(t_env *env_list);

void	built_in_export(t_command **cmd, t_env **env_list);

#endif