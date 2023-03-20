/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   share.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:07:32 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/14 15:40:28 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARE_H
# define SHARE_H

/*
	<title>
		token
	<sub>
		
	<struct>
		type : token 유형
		str : token 내용물
		quote : token 내용물에서 인용구의 위치
		next : 다음 토큰을 연결해주는 포인터
*/
typedef struct s_token
{
	char	type;
	char	*str;
	char	*quote;
	t_token	*next;
}	t_token;

/*
	<title>
		var(env_list)
	<sub>

	<struct>
		name :
		val :
		mean :
		status :
		next : 
*/
typedef struct s_var
{
	char		*name;
	char		*val;
	char		mean;
	int			status;
	t_var		*next;
}	t_var;

/*
	<title>
		command
	<sub>

	<struct>
		next :
*/
typedef struct s_command
{
	t_command	*next;
}	t_command;

#endif
