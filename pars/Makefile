CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rc
NAME = pars.a
HEADER = ./include/pars.h
RM = rm -f
SRC = ./srcs/pars_list_token_utils2 ./srcs/rotate_env_token ./srcs/mix_token ./srcs/chk_have_token ./srcs/chk_oper_token ./srcs/env_search ./srcs/env_search2 ./srcs/free_array ./srcs/make_com ./srcs/make_token ./srcs/pars_com ./srcs/removing_quote ./srcs/pars_line ./srcs/pars_list_token_utils ./srcs/pars_split_utils ./srcs/pars_utils ./srcs/pars_utils2 ./srcs/pars_utils3 ./srcs/record_builtin ./srcs/trim_token ./srcs/word_cnt
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
