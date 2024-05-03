/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-alo <sait-alo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 07:56:35 by sait-alo          #+#    #+#             */
/*   Updated: 2024/04/30 07:56:43 by sait-alo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_input(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if ((!ft_isdigit(s[i]) && (s[i] != '-' && s[i] != '+' && s[i] != ' '))
			|| ((s[i] == '-' || s[i] == '+') && !ft_isdigit(s[i + 1]))
			|| ((s[i] == '-' || s[i] == '+') && ft_isdigit(s[i - 1])))
			exit_error("Error\n", s, NULL, NULL);
}

static int	labelling(t_stack *stk)
{
	int	i;
	int	j;
	int	rank;

	i = 0;
	stk->clone = malloc(stk->size * sizeof(int));
	if (!stk->clone)
		return (-1);
	while (i < stk->size)
	{
		j = 0;
		rank = -1;
		while (j < stk->size)
			if (stk->stack[j++] <= stk->stack[i])
				rank++;
		stk->clone[i] = rank;
		i++;
	}
	i = -1;
	while (++i < stk->size)
		stk->stack[i] = stk->clone[i];
	free(stk->clone);
	return (0);
}

static char	*join_args(int ac, char **av)
{
	int		i;
	char	*args;
	char	*tmp;

	i = 1;
	args = NULL;
	tmp = NULL;
	while (i < ac)
	{
		if (is_void(av[i]))
			exit_error("Error\n", NULL, args, NULL);
		tmp = args;
		args = ft_strjoin(tmp, av[i]);
		if (!args)
			return (NULL);
		free(tmp);
		tmp = args;
		args = ft_strjoin(tmp, " ");
		if (!args)
			return (NULL);
		i++;
		free(tmp);
	}
	return (args);
}

static int	process_input(t_push_swap *stacks, int ac, char **av)
{
	char	*args;

	args = join_args(ac, av);
	if (!args)
		return (-1);
	check_input(args);
	stacks->a.size = count_nums(args, ' ');
	get_nums(args, stacks);
	stacks->b.stack = malloc(stacks->a.size * sizeof(int));
	if (!stacks->b.stack)
		return (-1);
	stacks->a.top = stacks->a.size - 1;
	stacks->b.top = -1;
	return (free(args), 0);
}

int	main(int ac, char **av)
{
	t_push_swap	stacks;

	stacks = (t_push_swap){0};
	if (ac >= 2)
	{
		if (process_input(&stacks, ac, av))
			return (free(stacks.a.stack), free(stacks.b.stack), -1);
		if (!is_sorted(&stacks.a)
			|| (stacks.a.size <= 5 && performe_easy_sort(&stacks)))
			return (free(stacks.a.stack), free(stacks.b.stack), 0);
		if (labelling(&stacks.a))
			return (free(stacks.a.stack), free(stacks.b.stack), -1);
		conquer(&stacks);
		push_back(&stacks);
	}
	return (free(stacks.a.stack), free(stacks.b.stack), 0);
}
