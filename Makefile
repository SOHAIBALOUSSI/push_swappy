NAME = push_swap
CC = cc
#CFLAGS = -Wall -Wextra -Werror -g3

SRC = main.c args_parsing.c push.c swap.c
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
	@rm -rf $(OBJ) 

fclean : clean
	@rm -rf $(NAME)


.PHONY : all clean fclean 