CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rc
NAME = pars.a
HEADER = ./include/pars.h
RM = rm -f
SRC = ./srcs/utils/pars_list_token_utils \
	  ./srcs/utils/pars_list_token_utils2 \
	  ./srcs/utils/pars_split_utils \
	  ./srcs/utils/pars_utils \
	  ./srcs/utils/pars_utils2 \
	  ./srcs/utils/pars_utils3 \
	  ./srcs/utils/child_signal \
	  ./srcs/tokenizer/chk_close_quote \
	  ./srcs/tokenizer/make_token \
	  ./srcs/tokenizer/mix_token \
	  ./srcs/tokenizer/rotate_env_token \
	  ./srcs/tokenizer/env_search \
	  ./srcs/tokenizer/env_search2 \
	  ./srcs/tokenizer/chk_oper_token \
	  ./srcs/command/make_com \
	  ./srcs/command/pars_com \
	  ./srcs/tokenizer/removing_quote \
	  ./srcs/pars_line \
	  ./srcs/command/record_builtin \
	  ./srcs/tokenizer/trim_token \
	  ./srcs/command/word_cnt
SRCC = $(addsuffix .c, $(SRC))
OBJ = $(addsuffix .o, $(SRC))

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ -I .

clean : 
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
