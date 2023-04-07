/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:46:19 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/07 17:28:58 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef EXIT_H
# define EXIT_H

# include "../../include/execute.h"

int			check_exit_syntax(char *exit_val);
void		built_in_exit(t_command **cmd, t_env **env_list, int cmd_cnt);
long long	ft_atol(char *str);
int			print_exit_numeric_error(char *err_str);
void		exit_error_ctl(char *err_msg);

#endif