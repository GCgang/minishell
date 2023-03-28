/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:22:47 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/03/28 19:44:16 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARS_H
# define PARS_H

# include "../../share/struct.h"
# include "../../share/init.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
void	*ft_memset(void *ptr, int value, size_t num);
void	str_tolower(char *str);
void	ft_bzero(void *ptr, size_t num);
char	*ft_itoa(int n);

t_token	*lstnew_token(char type, char *val);
void	lstadd_back_token(t_token **lst, t_token *new);
void	lstdelone_token(t_token *lst);
void	lstclear_token(t_token **lst);
void	lstdelone_token_elem(t_token *before, t_token *now);

void	pars_line(char *line, t_token **token, t_env **env_list);
int		chk_have_token(char *line, char *meta);
int		make_token(char *line, char *meta, t_token **token);
int		trim_token(t_token **token);
int		chk_oper_token(t_token *token);
int		removing_quote(t_token **token);
int		env_search(t_token *token, t_env *env_list);
void	word_cnt(t_token **token, t_command *com);
int		make_com(t_token **token, t_env **env_list, t_command **com);
int		pars_com(t_token **token, t_command *com);
void	free_array(char **arr);
int		mix_token(t_token **token);
int		rotate_env_token(t_token **token, t_env **env_list);
void	trim_env_token(t_token *token, t_env *env_list, int **loca);
int		trans_env_token(t_token *token, char **tgt, int **loca);

void	record_builtin(t_command **com, t_env *env_list);
int		record_path(t_command **com, t_env *env_list);

void	exec(t_command **cmd, t_env **env_list);

#endif
