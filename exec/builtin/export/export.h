/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:46:21 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/26 19:53:38 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef EXPORT_H
# define EXPORT_H

# include "../../include/execute.h"

int		check_export_syntax(char *cmd);
void	print_export(t_env *env_list);
t_env	*sort_export(t_env *env_list);
void	update_export_envp(t_env **env_list, char *name);
void	built_in_export(t_command **cmd, t_env **env_list);

#endif