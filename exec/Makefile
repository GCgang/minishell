CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rc
NAME = exec.a
HEADER = ./include/builtin.h ./inclue/execute.h
RM = rm -f
SRC = ./builtin/cd/cd ./builtin/echo/echo ./builtin/env/env ./builtin/export/export ./builtin/exit/exit ./builtin/pwd/pwd ./builtin/unset/unset ./execute/execute ./execute/ft_atoi ./execute/ft_isalpha ./execute/ft_isdigit ./execute/ft_putchar_fd ./execute/ft_putstr_fd ./execute/ft_strcmp
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
