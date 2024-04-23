#include "push_swap.h"

void	swap(t_stack *s, char stk)
{
	int	tmp;

	if (s->size < 2)
		return ;
	tmp = s->stack[s->top];
	s->stack[s->top] = s->stack[s->top - 1];
	s->stack[s->top - 1] = tmp;
	if (stk == 'a')
		write(1, "sa\n", 3);
	if (stk == 'b')
		write(1, "sb\n", 3);
	else
		return ;
}
void	ss(t_stack *a, t_stack *b)
{
	swap(a, 0);
	swap(b, 0);
	write(1, "ss\n", 3);
}