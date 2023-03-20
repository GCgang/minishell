/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jun <jun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:46:17 by hyeoan            #+#    #+#             */
/*   Updated: 2023/03/21 01:15:51 by jun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef ENV_H
# define ENV_H

# include "../../execute.h"

void	built_in_env(t_command **cmd, t_env *env_list);

#endif