# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 14:45:37 by jaehjoo           #+#    #+#              #
#    Updated: 2023/04/12 22:21:21 by jaehjoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Werror -Wall -Wextra
CF_FLAGS = -L/Users/hyeoan/.brew/opt/readline/lib -lreadline
OBJ_FLAGS = -I/Users/hyeoan/.brew/opt/readline/include
PARS = -L./pars -lpars
EXEC = -L./exec -lexec
PARSA = ./pars/pars.a
EXECA = ./exec/exec.a
RM = rm -rf
SRC = minishell \
	  init_env \
	  init_list_utils \
	  init_signal \
	  init_utils \
	  list_clear_env \
	  list_clear_com \
	  clear_all \
	  err_msg \
	  exec_signal
SRCC = $(addsuffix .c, $(addprefix share/, $(SRC)))
OBJ = $(SRCC:c=o)
PARS_SRC = ./pars/srcs/utils/pars_list_token_utils \
	  	   ./pars/srcs/utils/pars_list_token_utils2 \
	  	   ./pars/srcs/utils/pars_split_utils \
		   ./pars/srcs/utils/pars_utils \
		   ./pars/srcs/utils/pars_utils2 \
		   ./pars/srcs/utils/pars_utils3 \
		   ./pars/srcs/tokenizer/chk_close_quote \
		   ./pars/srcs/tokenizer/make_token \
		   ./pars/srcs/tokenizer/mix_token \
		   ./pars/srcs/tokenizer/rotate_env_token \
		   ./pars/srcs/tokenizer/env_search \
		   ./pars/srcs/tokenizer/env_search2 \
		   ./pars/srcs/tokenizer/env_search3 \
		   ./pars/srcs/tokenizer/chk_oper_token \
		   ./pars/srcs/command/make_com \
		   ./pars/srcs/command/pars_com \
		   ./pars/srcs/tokenizer/removing_quote \
		   ./pars/srcs/pars_line \
		   ./pars/srcs/command/record_builtin \
		   ./pars/srcs/tokenizer/trim_token \
		   ./pars/srcs/command/word_cnt
PARS_SRCC = $(addsuffix .c, $(PARS_SRC))
EXEC_SRC = ./exec/builtin/cd/cd \
		   ./exec/builtin/echo/echo \
		   ./exec/builtin/env/env \
		   ./exec/builtin/export/export \
		   ./exec/builtin/exit/exit \
		   ./exec/builtin/pwd/pwd \
		   ./exec/builtin/unset/unset \
		   ./exec/execute/execute \
		   ./exec/execute/execute_built_in \
		   ./exec/execute/execve_cmd \
		   ./exec/execute/execute_utils \
		   ./exec/redirection/redirection \
		   ./exec/redirection/process_io_dup \
		   ./exec/here_doc/here_document
EXEC_SRCC = $(addsuffix .c, $(EXEC_SRC))
HEADER = ./share/init.h
INCLUDES = -I./share -I./pars/include
NAME = minishell

all : $(NAME)

$(NAME): $(OBJ) $(PARSA) $(EXECA)
			$(CC) $(CFLAGS) $(CF_FLAGS) $(PARSA) $(EXECA) $(OBJ) $(INCLUDES) -o $(NAME)

%.o: %.c $(HEADER)
			$(CC) -c $(CFLAGS) $(OBJ_FLAGS) $< -o $@ $(INCLUDES)

$(PARSA): $(PARS_SRCC)
			make -sC ./pars/

$(EXECA): $(EXEC_SRCC)
			make -sC ./exec/

clean:
			$(RM) $(OBJ)
			make -sC ./pars clean
			make -sC ./exec clean

fclean:
			make -s clean
			$(RM) $(NAME) $(OBJ) $(PARSA) $(EXECA)

re:
			make -s fclean
			make -s all

.PHONY: all clean fclean re
