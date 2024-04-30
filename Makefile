NAME = push_swap
CHECKER = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRC =	$(addprefix ./mandatory/, main.c args_parsing.c push_and_swap.c rotate.c \
		rev_rotate.c performe_easy_sort.c conquer.c tools.c)

BSRC = $(addprefix ./bonus/, checker.c args_parsing.c push_and_swap.c rotate.c \
		rev_rotate.c tools.c)

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

LIBFT = ./libft/libft.a

.c.o : 
	$(CC) $(CFLAGS) -c -o $@ $<

all : $(NAME)

bonus : $(CHECKER)

$(CHECKER) : $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) -o $(CHECKER) $(LIBFT)
libft :
	@make -C libft/

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)

clean :
	@rm -f $(OBJ) $(BOBJ)

fclean : clean
	@rm -f  $(NAME) $(CHECKER)

re : fclean all

.PHONY : all clean fclean re 
