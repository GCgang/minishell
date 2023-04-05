/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:46:08 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/28 12:49:20 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef CD_H
# define CD_H

# include "../../include/execute.h"

void	update_pwd(t_env **env_list, char *old_pwd);
void	change_home_dir(t_env **env_list);
void	change_new_dir(t_env **env_list, char *name);
void	change_oldpwd_dir(t_env **env_list);
void	built_in_cd(t_command **cmd, t_env **env_list);

#endif