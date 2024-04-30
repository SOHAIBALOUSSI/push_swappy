/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conquer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-alo <sait-alo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 07:57:06 by sait-alo          #+#    #+#             */
/*   Updated: 2024/04/30 07:57:09 by sait-alo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	get_max(t_stack *stk)
{
	int	i;
	int	max;
	int	max_pos;

	i = 0;
	max_pos = 0;
	max = stk->stack[0];
	while (i < stk->size)
	{
		if (stk->stack[i] > max)
		{
			max = stk->stack[i];
			max_pos = i;
		}
		i++;
	}
	return (max_pos);
}

void	conquer(t_push_swap *stks)
{
	int	value;
	int	range;

	value = 4 * (stks->a.size <= 250) + 10 * (stks->a.size > 250);
	while (stks->a.size > 0)
	{
		range = stks->a.size / value;
		if (stks->a.stack[stks->a.top] < stks->b.size)
			pb(&stks->a, &stks->b);
		else if (stks->a.stack[stks->a.top] <= stks->b.size + range)
		{
			pb(&stks->a, &stks->b);
			rb(&stks->b, 1);
		}
		else
			ra(&stks->a, 1);
	}
}

void	push_back(t_push_swap *stks)
{
	int	size;
	int	max;

	while (stks->b.size > 0)
	{
		size = stks->b.size;
		max = get_max(&stks->b);
		if (max <= size / 2)
		{
			while (max-- >= 0)
				rrb(&stks->b, 1);
			pa(&stks->a, &stks->b);
		}
		else if ((max > size / 2))
		{
			while (max++ < size - 1)
				rb(&stks->b, 1);
			pa(&stks->a, &stks->b);
		}
	}
}
