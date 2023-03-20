#ifndef PARS_H
# define PARS_H

# include "../../share/init.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strtrim(char const *str, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
void	*ft_memset(void *ptr, int value, size_t num);
void	str_tolower(char *str);
char	*strjoin_append(char const *s1, char const *s2, char c);
void	ft_bzero(void *ptr, size_t num);

t_token	*lstnew_token(char type, char *val);
void	lstadd_back_token(t_token **lst, t_token *new);
void	lstdelone_token(t_token *lst, void (*del)(void *));
void	lstclear_token(t_token **lst, void (*del)(void *));
t_token	*connect_newlst(t_token *tmp, char *val);

void	pars_line(char *line, t_token **token, t_env **env_list);
int		chk_have_token(char *line, char *meta);
void	make_token(char *line, char *meta, t_token **token);
void	trim_token(t_token **token);
void	extend_trim_token(t_token *tgt, int num);
int		chk_oper_token(t_token *token);
void	pars_extra_token(t_token **token, t_env *env_list);
void	env_search(t_token *token, t_env *env_list);
void	split_word_ifs(t_token **token, t_env *env_list);
void	remove_quote(t_token *token);
void	word_cnt(t_token **token, t_command *com);
int		make_com(t_token **token, t_env **env_list, t_command **com);
int		pars_com(t_token **token, t_env **env_list, t_command *com);
int		pars_oper(t_token **token, t_env **env_list, t_command *com);
void	change_status(t_env **env_list, int status);
void	free_array(char **arr);

int		heredoc(t_command *com, t_env **env_list);
void	record_extra(t_command *com, t_env *env_list);

#endif
