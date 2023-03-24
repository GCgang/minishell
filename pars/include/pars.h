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

t_token	*lstnew_token(char type, char *val);
void	lstadd_back_token(t_token **lst, t_token *new);
void	lstdelone_token(t_token *lst, void (*del)(void *));
void	lstclear_token(t_token **lst, void (*del)(void *));
void	lstdelone_token_elem(t_token *before, t_token *now,
			void (*del)(void *));

void	pars_line(char *line, t_token **token, t_env **env_list);
int		chk_have_token(char *line, char *meta);
void	make_token(char *line, char *meta, t_token **token);
void	trim_token(t_token **token);
int		chk_oper_token(t_token *token, t_env **env_list);
void	pars_extra_token(t_token **token, t_env *env_list);
void	env_search(t_token *token, t_env *env_list);
void	remove_quote(t_token *token);
void	word_cnt(t_token **token, t_command *com);
int		make_com(t_token **token, t_env **env_list, t_command **com);
int		pars_com(t_token **token, t_env **env_list, t_command *com);
int		pars_oper(t_token **token, t_env **env_list, t_command *com);
void	change_status(t_env **env_list, int status);
void	free_array(char **arr);
void	mix_token(t_token **token);
void	rotate_env_token(t_token **token, t_env **env_list);

int		heredoc(t_command *com, t_env **env_list);
void	record_builtin(t_command **com, t_env *env_list);
int		record_path(t_command **com, t_env *env_list);

#endif
