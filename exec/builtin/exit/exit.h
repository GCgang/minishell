/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:46:19 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/04 20:23:10 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef EXIT_H
# define EXIT_H

# include "../../include/execute.h"

int			check_exit_syntax(char *exit_val);
void		built_in_exit(t_command **cmd);
long long	ft_atol(const char *str);

#endif