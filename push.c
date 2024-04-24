#include "push_swap.h"

void	push_a(t_stack *a, t_stack *b)
{
	if (b->size <= 0)
		return ;
	a->top++;
	a->size++;
	a->stack[a->top] = b->stack[b->top];
	b->top--;
	b->size--;
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