/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:46:14 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/22 17:03:02 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef ECHO_H
# define ECHO_H

# include "../../include/execute.h"

void	built_in_echo(t_command **cmd, t_env *env_list);
void	check_echo_option(char **cmd, int *option_n, int *idx);

#endif