/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:46:17 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/12 17:08:48 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef ENV_H
# define ENV_H

# include "../../include/execute.h"

void	built_in_env(t_command **cmd, t_env **env_list);
void	init_envp(t_env **env_list, char *name, char *val);
char	*get_name(t_env *env_list, char *name);
char	*get_value(t_env *env_list, char *name);
void	env_error_msg(char *err_word);

#endif