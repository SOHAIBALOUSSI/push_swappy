#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# define RED "\033[1;31m"

#include "./libft/libft.h"
#include <limits.h>


typedef struct	s_stack
{
	int	*stack;
	int	top;
	int	size;
	int flag;
}				t_stack;

typedef struct	s_push_swap
{
	t_stack a;
	t_stack b;
}				t_push_swap;

/* Parsing araguments */
int		fatoi(char *str, int *nums, char *arg);
int		count_nums(char *s, char c);
void	get_nums(char *arg, t_push_swap *stack);
void	exit_error(char *error_msg, char *str, char *args, int *array);
void	check_input(char *s);

/* OPERATIONS */

void	swap(t_stack *s, char stk);
void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b);
void	rotate(t_stack *st, char stack);
void 	rr(t_stack *a, t_stack *b);
void	rev_rotate(t_stack *st, char stack);
void 	rrr(t_stack *a, t_stack *b);


#endif /* PUSH_SWAP_H */