#ifndef INIT_H
# define INIT_H

typedef struct s_token
{
	char			type;
	char			*val;
	char			*quote;
	struct s_token	*next;
}	t_token;

typedef struct	s_env
{
	char			*name;
	char			*val;
	char			mean;
	int				status;
	struct s_env	*next;
}	t_env;

typedef struct s_command
{
	int		order;
	char	**word;
	char	*path;
	int		path_err;
	char	*oper;
	char	*oper_val;
	char	val_type;
	char	builtin;
	int		std_in;
	int		std_out;
	int		std_err;
	int		std_in_dup1;
	int		std_out_dup1;
	int		pipe;
	int		pipe_in;
	int		pipe_out;
	struct s_command	*next;
}	t_command;

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../pars/include/pars.h"

char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);

void	lstadd_front_env(t_env **lst, t_env *new);
void	lstadd_back_env(t_env **lst, t_env *new);
void	lstdelone_env(t_env *lst, void (*del)(void *));
void	lstclear_env(t_env **lst, void (*del)(void *));
t_env	*lstnew_env(char *name, char *val);

void	init_signal(void);
void	heredoc_sigint_handler(int sig);
int		init_env(char **envp, t_env **env_list);

#endif
