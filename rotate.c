#include "push_swap.h"

void	rotate(t_stack *st, char stack)
{
	int tmp;
	int top;

	if (st->size < 2)
		return ;
	tmp = st->stack[st->top];
	top = st->top;
	while (top >= 0)
	{
		st->stack[top] = st->stack[top - 1];
		top--;
	}
	st->stack[0] = tmp;
	if (stack == 'a')
		write(1, "ra\n", 3);
	else if (stack == 'b')
		write(1, "rb\n", 3);
	else
		return ;
}

void rr(t_stack *a, t_stack *b)
{
	rotate(a, 0);
	rotate(b, 0);
	write (1, "rr\n", 3);
}

void	rev_rotate(t_stack *st, char stack)
{
	int tmp;
	int i;
	int top;

	if (st->size < 2)
		return ;
	i = 0;
    tmp = st->stack[0];
	top = st->top;
	while (i < top)
	{
		st->stack[i] = st->stack[i + 1];
		i++;
	}
	st->stack[top] = tmp;
	if (stack == 'a')
		write(1, "rra\n", 4);
	else if (stack == 'b')
		write(1, "rrb\n", 4);
	else
		return ;
}

void rrr(t_stack *a, t_stack *b)
{
    rev_rotate(a, 0);
    rev_rotate(b, 0);
    write(1, "rrr\n", 4);
}