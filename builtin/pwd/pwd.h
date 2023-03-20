/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:44:52 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/20 16:15:59 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PWD_H
# define PWD_H
# define PATH_MAX 1024 // limit.h -> PATH_MAX 1024 (del)
# include "../../execute.h"

void	built_in_pwd(t_env *env_list);

#endif