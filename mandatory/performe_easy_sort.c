/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   performe_easy_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-alo <sait-alo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 07:56:54 by sait-alo          #+#    #+#             */
/*   Updated: 2024/04/30 07:56:58 by sait-alo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min(t_stack *stk)
{
	int	i;
	int	min;

	i = -1;
	min = stk->stack[0];
	while (++i < stk->size)
		if (min > stk->stack[i])
			min = stk->stack[i];
	return (min);
}

static void	sort_three(t_stack *stks)
{
	int	top;
	int	middle;
	int	bottom;

	top = stks->stack[2];
	middle = stks->stack[1];
	bottom = stks->stack[0];
	if (top > middle && middle < bottom && top < bottom)
		sa(stks, 1);
	else if (top > middle && middle > bottom)
	{
		sa(stks, 1);
		rra(stks, 1);
	}
	else if (top > middle && middle < bottom && top > bottom)
		ra(stks, 1);
	else if (top < middle && middle > bottom && bottom > top)
	{
		sa(stks, 1);
		ra(stks, 1);
	}
	else
		rra(stks, 1);
}

static void	sort_four(t_push_swap *stks)
{
	int	min;

	min = get_min(&stks->a);
	while (stks->a.stack[stks->a.top] != min)
		ra(&stks->a, 1);
	if (!is_sorted(&stks->a))
		return ;
	pb(&stks->a, &stks->b);
	sort_three(&stks->a);
	pa(&stks->a, &stks->b);
}

static void	sort_five(t_push_swap *stks)
{
	int	min;

	min = get_min(&stks->a);
	if (stks->a.stack[0] == min)
		rra(&stks->a, 1);
	else if (stks->a.stack[1] == min)
	{
		rra(&stks->a, 1);
		rra(&stks->a, 1);
	}
	else
	{
		while (stks->a.stack[stks->a.top] != min)
			ra(&stks->a, 1);
	}
	if (!is_sorted(&stks->a))
		return ;
	pb(&stks->a, &stks->b);
	sort_four(stks);
	pa(&stks->a, &stks->b);
}

int	performe_easy_sort(t_push_swap *stks)
{
	if (stks->a.size == 2)
	{
		if (stks->a.stack[0] < stks->a.stack[1])
			sa(&stks->a, 1);
	}
	else if (stks->a.size == 3)
		sort_three(&stks->a);
	else if (stks->a.size == 4)
		sort_four(stks);
	else if (stks->a.size == 5)
		sort_five(stks);
	return (1);
}
