NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRC =	main.c args_parsing.c push_and_swap.c rotate.c \
		rev_rotate.c performe_easy_sort.c conquer.c tools.c
OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

.c.o : 
	$(CC) $(CFLAGS) -c -o $@ $<

all : $(NAME)

libft :
	@make -C libft/

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)

clean :
	@rm -f $(OBJ) 

fclean : clean
	@rm -f  $(NAME)

re : fclean all

.PHONY : all clean fclean re 
