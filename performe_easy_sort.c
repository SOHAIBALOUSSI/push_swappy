#include "push_swap.h"

void	sort_three(t_push_swap *stks)
{
	
}

void 	performe_easy_sort(t_push_swap *stks)
{
	if (stks->a.size == 2)
	{
		if (stks->a.stack[0] < stks->a.stack[1])
			swap(&stks->a, 'a');
	}
	else if (stks->a.size == 3)
		sort_three();
	else if (stks->a.size == 4)
		sort_four();
	else if (stks->a.size == 5)
		sort_five();
}