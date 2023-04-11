/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:46:08 by hyeoan            #+#    #+#             */
/*   Updated: 2023/04/11 18:23:15 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_H
# define CD_H

# include "../../include/execute.h"

void	update_pwd(t_env **env_list, char *old_pwd);
void	change_home_dir(t_env **env_list);
void	change_new_dir(t_env **env_list, char *name);
void	change_oldpwd_dir(t_env **env_list);
void	built_in_cd(t_command **cmd, t_env **env_list);

#endif