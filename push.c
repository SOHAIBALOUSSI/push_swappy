#include "push_swap.h"

void	rotate(t_stack *st, char stack)
{
	int tmp;
	int size;
	int top;

	if (st->size < 2)
		return ;
	tmp = st->stack[st->top];
	size = st->size;
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

void rotate_both(t_stack *a, t_stack *b)
{
	rotate(a, 'a');
	rotate(b, 'b');
	write (1, "rr\n", 3);
}


void	push_a(t_stack *a, t_stack *b)
{
	if (b->size <= 0)
		return ;
	b->top--;
	b->size--;
	a->stack[a->top] = b->stack[b->top];
	a->top++;
	a->size++;
	write(1, "pa\n", 3);
}


void	push_b(t_stack *a, t_stack *b)
{
	if (a->size <= 0)
		return ;
	b->top++;
	b->size++;
	b->stack[b->top] = a->stack[a->top];
	a->top--;
	a->size--;
	write(1, "pb\n", 3);
}