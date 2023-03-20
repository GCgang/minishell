CFLAGS = -Werror -Wall -Wextra
CF_FLAGS = -L/Users/jaehjoo/.brew/opt/readline/lib -lreadline
OBJ_FLAGS = -I/Users/jaehjoo/.brew/opt/readline/include
PARS = -L./pars -lpars
PARSA = ./pars/pars.a
RM = rm -rf
SRC = minishell init_env init_list_utils init_signal init_utils list_clear
SRCC = $(addsuffix .c, $(addprefix share/, $(SRC)))
OBJ = $(SRCC:c=o)
HEADER = ./share/init.h
INCLUDES = -I./share -I./pars/include
NAME = minishell

all : $(NAME)

$(NAME): $(OBJ) $(PARSA)
			$(CC) $(CFLAGS) $(CF_FLAGS) $(PARSA) $(OBJ) $(INCLUDES) -o $(NAME)

%.o: %.c $(HEADER)
			$(CC) -c $(CFLAGS) $(OBJ_FLAGS) $< -o $@ $(INCLUDES)

$(PARSA):
			make -sC ./pars/

clean:
			$(RM) $(NAME) $(OBJ)
			make -sC ./pars clean

fclean: clean
			$(RM) $(NAME) $(OBJ) $(PARSA)

re:
			make fclean
			make all

.PHONY: all clean fclean re
