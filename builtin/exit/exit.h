/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:46:19 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/20 16:34:54 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef EXIT_H
# define EXIT_H

# include "../../execute.h"

void	built_in_exit(t_command **cmd, t_env *env_list, pid_t pid);

#endif