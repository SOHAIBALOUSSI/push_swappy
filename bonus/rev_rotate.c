/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-alo <sait-alo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 07:57:47 by sait-alo          #+#    #+#             */
/*   Updated: 2024/04/30 07:57:50 by sait-alo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_stack *a)
{
	int	tmp;
	int	i;
	int	top;

	if (a->size < 2)
		return ;
	i = 0;
	tmp = a->stack[0];
	top = a->top;
	while (i < top)
	{
		a->stack[i] = a->stack[i + 1];
		i++;
	}
	a->stack[top] = tmp;
}

void	rrb(t_stack *b)
{
	int	i;
	int	tmp;
	int	top;

	if (b->size < 2)
		return ;
	i = 0;
	tmp = b->stack[0];
	top = b->top;
	while (i < top)
	{
		b->stack[i] = b->stack[i + 1];
		i++;
	}
	b->stack[top] = tmp;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
