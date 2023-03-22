/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend_trim_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:34 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/21 15:44:34 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pars.h"

/*
	extend_trim_token
	1. 공백 제외 다른 토큰들을 분할하여 각각의 토큰으로 저장할 때 사용
*/
void	extend_trim_token(t_token *tgt, int num)
{
	t_token	*tmp;
	char	*tmp_str;
	char	*str;

	tmp = tgt;
	tmp_str = tmp->val;
	tmp->val = ft_substr(tmp_str, 0, num);
	str = ft_substr(tmp_str, num, ft_strlen(tmp_str));
	free(tmp_str);
	tmp->next = connect_newlst(tmp, str);
}
