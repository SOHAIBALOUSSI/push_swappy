#include "push_swap.h"

void	rotate(t_stack *st, char stack)
{
	int tmp;
	int size;
	int top;
	if (st->size < 2)
		return ;
	tmp = st->stack[st->top + 1];
	size = st->size;
	top = st->top;
	top++;
	while (size--)
	{
		st->stack[top] = st->stack[top + 1];
		top++;
	}
	st->stack[--top] = tmp;
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
	a->stack[a->top] = b->stack[b->top];
	b->top++;
	a->size++;
	a->top--;
	b->size--;
	write(1, "pa\n", 3);
}


void	push_b(t_stack *a, t_stack *b)
{
	if (a->size <= 0)
		return ;
	b->stack[b->top] = a->stack[a->top];
	// a->stack[a->top] = 0;
	a->top++;
	b->top--;
	a->size--;
	b->size++;
	write(1, "pb\n", 3);
}