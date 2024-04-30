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

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>

# define SA 1
# define SB 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

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
void	exit_free(char *error_msg, int *a, int *b);
void	exit_error(char *error_msg, char *str, char *args, int *array);

/* OPERATIONS */

void	sa(t_stack *a, char print);
void	sb(t_stack *b, char print);
void	ss(t_stack *a, t_stack *b, int print);
void	pa(t_stack *a, t_stack *b, int print);
void	pb(t_stack *a, t_stack *b, int print);
void	ra(t_stack *a, char print);
void	rb(t_stack *b, char print);
void	rr(t_stack *a, t_stack *b, int print);
void	rra(t_stack *a, char print);
void	rrb(t_stack *b, char print);
void	rrr(t_stack *a, t_stack *b, int print);

/*	Sorting	*/

int		performe_easy_sort(t_push_swap *stks);
void	conquer(t_push_swap *stks);
void	push_back(t_push_swap *stks);
int		is_sorted(t_stack *a);

#endif /* CHECKER_H */
