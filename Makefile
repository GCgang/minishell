CFLAGS = -Werror -Wall -Wextra
CF_FLAGS = -L/Users/jun/.brew/opt/readline/lib -lreadline
OBJ_FLAGS = -I/Users/jun/.brew/opt/readline/include
PARS = -L./pars -lpars
PARSA = ./pars/pars.a
EXEC = -L./exec -lexec
EXECA = ./exec/exec.a
RM = rm -rf
SRC = minishell init_env init_list_utils init_signal init_utils list_clear
SRCC = $(addsuffix .c, $(addprefix share/, $(SRC)))
OBJ = $(SRCC:c=o)
HEADER = ./share/init.h
INCLUDES = -I./share -I./pars/include
NAME = minishell

all : $(NAME)

$(NAME): $(OBJ) $(PARSA) $(EXECA)
			$(CC) $(CFLAGS) $(CF_FLAGS) $(PARSA) $(EXECA) $(OBJ) $(INCLUDES) -o $(NAME)

%.o: %.c $(HEADER)
			$(CC) -c $(CFLAGS) $(OBJ_FLAGS) $< -o $@ $(INCLUDES)

$(PARSA):
			make -sC ./pars/

$(EXECA):
			make -sC ./exec/

clean:
			$(RM) $(NAME) $(OBJ)
			make -sC ./pars clean
			make -sC ./exec clean

fclean: clean
			$(RM) $(NAME) $(OBJ) $(PARSA) $(EXECA)

re:
			make fclean
			make all

.PHONY: all clean fclean re
