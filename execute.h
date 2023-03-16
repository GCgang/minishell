/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:00:55 by hyeoan            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/03/16 22:53:10 by hyeoan           ###   ########.fr       */
=======
<<<<<<<< HEAD:execute.h
/*   Updated: 2023/03/16 22:31:06 by hyeoan           ###   ########.fr       */
========
/*   Updated: 2023/03/16 22:54:24 by hyeoan           ###   ########.fr       */
>>>>>>>> 08698c52d3c56c202fb69a561ab072db58466aa3:excute.h
>>>>>>> 08698c52d3c56c202fb69a561ab072db58466aa3
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
<<<<<<< HEAD
int		ft_strcmp(char *s1, char *s2);
=======
<<<<<<<< HEAD:execute.h
int		ft_strcmp(char *s1, char *s2);
========
int		ft_strncmp(const char *s1, const char *s2, size_t n);
>>>>>>>> 08698c52d3c56c202fb69a561ab072db58466aa3:excute.h
>>>>>>> 08698c52d3c56c202fb69a561ab072db58466aa3

#endif