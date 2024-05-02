/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-alo <sait-alo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 07:57:57 by sait-alo          #+#    #+#             */
/*   Updated: 2024/04/30 07:57:59 by sait-alo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	int	tmp;
	int	top;

	if (a->size < 2)
		return ;
	tmp = a->stack[a->top];
	top = a->top;
	while (top >= 0)
	{
		a->stack[top] = a->stack[top - 1];
		top--;
	}
	a->stack[0] = tmp;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	int	tmp;
	int	top;

	if (b->size < 2)
		return ;
	tmp = b->stack[b->top];
	top = b->top;
	while (top >= 0)
	{
		b->stack[top] = b->stack[top - 1];
		top--;
	}
	b->stack[0] = tmp;
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	write (1, "rr\n", 3);
}
