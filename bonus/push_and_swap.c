/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-alo <sait-alo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 07:57:30 by sait-alo          #+#    #+#             */
/*   Updated: 2024/04/30 07:57:33 by sait-alo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa(t_stack *a, t_stack *b)
{
	if (b->size <= 0)
		return ;
	a->top++;
	a->size++;
	a->stack[a->top] = b->stack[b->top];
	b->top--;
	b->size--;
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size <= 0)
		return ;
	b->top++;
	b->size++;
	b->stack[b->top] = a->stack[a->top];
	a->top--;
	a->size--;
}

void	sa(t_stack *a)
{
	int	tmp;

	if (a->size < 2)
		return ;
	tmp = a->stack[a->top];
	a->stack[a->top] = a->stack[a->top - 1];
	a->stack[a->top - 1] = tmp;
}

void	sb(t_stack *b)
{
	int	tmp;

	if (b->size < 2)
		return ;
	tmp = b->stack[b->top];
	b->stack[b->top] = b->stack[b->top - 1];
	b->stack[b->top - 1] = tmp;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}
