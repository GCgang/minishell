/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:00:55 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/16 22:31:06 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc execute.c strncmp.c ../builtin/cd/cd.c ../builtin/echo/echo.c ../builtin/env/env.c ../builtin/exit/exit.c ../builtin/export/export.c ../builtin/pwd/pwd.c ../builtin/unset/unset.c
#	ifndef EXECUTE_H
# define EXECUTE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "builtin.h"

void	execute_simple_built_in(char **argv);
int		ft_strcmp(char *s1, char *s2);

#endif