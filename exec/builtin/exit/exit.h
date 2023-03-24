/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:46:19 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/24 15:58:23 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef EXIT_H
# define EXIT_H

# include "../../include/execute.h"

int		check_exit_syntax(char *exit_val);
void	built_in_exit(t_command **cmd, t_env *env_list);

#endif