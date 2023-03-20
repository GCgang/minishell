CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rc
NAME = pars.a
HEADER = ./include/pars.h
RM = rm -f
SRC = ./srcs/change_status ./srcs/chk_have_token ./srcs/chk_oper_token ./srcs/env_search ./srcs/free_array ./srcs/heredoc ./srcs/make_com ./srcs/make_token ./srcs/pars_com ./srcs/pars_extra_token ./srcs/pars_line ./srcs/pars_list_token_utils ./srcs/pars_oper ./srcs/pars_split_utils ./srcs/pars_utils ./srcs/pars_utils2 ./srcs/record_extra ./srcs/remove_quote ./srcs/split_word_ifs ./srcs/trim_token ./srcs/word_cnt ./srcs/extend_trim_token
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