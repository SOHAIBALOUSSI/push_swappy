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


void	pa(t_stack *a, t_stack *b, int print)
{
	if (b->size <= 0)
		return ;
	a->top++;
	a->size++;
	a->stack[a->top] = b->stack[b->top];
	b->top--;
	b->size--;
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b, int print)
{
	if (a->size <= 0)
		return ;
	b->top++;
	b->size++;
	b->stack[b->top] = a->stack[a->top];
	a->top--;
	a->size--;
	if (print)
		write(1, "pb\n", 3);
}

void	sa(t_stack *a, char print)
{
	int	tmp;

	if (a->size < 2)
		return ;
	tmp = a->stack[a->top];
	a->stack[a->top] = a->stack[a->top - 1];
	a->stack[a->top - 1] = tmp;
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, char print)
{
	int	tmp;

	if (b->size < 2)
		return ;
	tmp = b->stack[b->top];
	b->stack[b->top] = b->stack[b->top - 1];
	b->stack[b->top - 1] = tmp;
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b, int print)
{
	sa(a, 0);
	sb(b, 0);
	if (print)
		write(1, "ss\n", 3);
}
