/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:46:26 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/06 17:06:09 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef UNSET_H
# define UNSET_H

# include "../../include/execute.h"

void	delete_envp(t_env *env_list, char *name);
void	built_in_unset(t_command **cmd, t_env *env_list);
#endif