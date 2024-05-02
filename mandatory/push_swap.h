/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-alo <sait-alo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 07:59:08 by sait-alo          #+#    #+#             */
/*   Updated: 2024/04/30 07:59:12 by sait-alo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int	*stack;
	int	*clone;
	int	top;
	int	size;
}				t_stack;

typedef struct s_push_swap
{
	t_stack	a;
	t_stack	b;
}				t_push_swap;

/* Parsing araguments */

void	check_input(char *s);
int		is_void(char *av);
void	get_nums(char *arg, t_push_swap *stack);
int		count_nums(char *s, char c);
int		fatoi(char *str, int *nums, char *arg);
void	exit_free(int *a, int *b);
void	exit_error(char *error_msg, char *str, char *args, int *array);

/* OPERATIONS */

void	sa(t_stack *a);
void	sb(t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/*	Sorting	*/

int		performe_easy_sort(t_push_swap *stks);
void	conquer(t_push_swap *stks);
void	push_back(t_push_swap *stks);
int		is_sorted(t_stack *a);

#endif /* PUSH_SWAP_H */
