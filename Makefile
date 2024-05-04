NAME = push_swap
CHECKER = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	$(addprefix ./mandatory/, main.c args_parsing.c push_and_swap.c rotate.c \
		rev_rotate.c performe_easy_sort.c conquer.c tools.c mini_libft.c)

BSRC = $(addprefix ./bonus/, checker.c args_parsing.c push_and_swap.c rotate.c \
		rev_rotate.c tools.c mini_libft.c get_next_line.c)

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

.c.o : 
	$(CC) $(CFLAGS) -c -o $@ $<

all : $(NAME)

bonus : $(CHECKER)

$(CHECKER) : $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) -o $(CHECKER)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	@rm -f $(OBJ) $(BOBJ)

fclean : clean
	@rm -f  $(NAME) $(CHECKER)

re : fclean all

.PHONY : all clean fclean re 
