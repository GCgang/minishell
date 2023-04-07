CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rc
NAME = exec.a
HEADER = ./include/builtin.h ./inclue/execute.h ./include/redirection.h ./include/here_doc.h
RM = rm -f
SRC = ./builtin/cd/cd ./builtin/echo/echo ./builtin/env/env ./builtin/export/export ./builtin/exit/exit ./builtin/pwd/pwd ./builtin/unset/unset ./execute/execute ./execute/execute_built_in ./execute/execve_cmd ./execute/execute_utils ./redirection/redirection ./redirection/process_io_dup ./here_doc/here_document
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
