#include "init.h"

void	clear_all(t_token **token, t_env **env_list, t_command **com)
{
	lstclear_token(token, &free);
	lstclear_env(env_list, &free);
	lstclear_com(com, &free);
}
