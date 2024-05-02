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

#include "checker.h"

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

static int	process_input(t_push_swap *stks, int ac, char **av)
{
	char	*args;

	args = join_args(ac, av);
	if (!args)
		return (-1);
	check_input(args);
	stks->a.size = count_nums(args, ' ');
	stks->a.stack = malloc(stks->a.size * sizeof(int));
	if (!stks->a.stack)
		return (-1);
	get_nums(args, stks);
	stks->b.stack = malloc(stks->a.size * sizeof(int));
	if (!stks->b.stack)
		return (-1);
	stks->a.top = stks->a.size - 1;
	stks->b.top = -1;
	free(args);
	return (0);
}

static int	do_op(t_push_swap *stks, char *inst)
{
	if (!ft_strncmp("sa\n", inst, 3))
		sa(&stks->a);
	else if (!ft_strncmp("sb\n", inst, 3))
		sb(&stks->a);
	else if (!ft_strncmp("ss\n", inst, 3))
		ss(&stks->a, &stks->b);
	else if (!ft_strncmp("pa\n", inst, 3))
		pa(&stks->a, &stks->b);
	else if (!ft_strncmp("pb\n", inst, 3))
		pb(&stks->a, &stks->b);
	else if (!ft_strncmp("ra\n", inst, 3))
		ra(&stks->a);
	else if (!ft_strncmp("rb\n", inst, 3))
		rb(&stks->b);
	else if (!ft_strncmp("rr\n", inst, 3))
		rr(&stks->a, &stks->b);
	else if (!ft_strncmp("rra\n", inst, 4))
		rra(&stks->a);
	else if (!ft_strncmp("rrb\n", inst, 4))
		rrb(&stks->b);
	else if (!ft_strncmp("rrr\n", inst, 4))
		rrr(&stks->a, &stks->b);
	else
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	char		*check;
	t_push_swap	stk;

	stk = (t_push_swap){0};
	if (ac >= 2)
	{
		if (process_input(&stk, ac, av))
			exit_free(NULL, stk.a.stack, stk.b.stack);
		check = get_next_line(STDIN_FILENO);
		while (check)
		{
			if (do_op(&stk, check) == -1)
				return (free(stk.a.stack), free(stk.b.stack),
					free(check), write(2, "Error\n", 6));
			free(check);
			check = get_next_line(STDIN_FILENO);
		}
		if (!is_sorted(&stk.a) && !stk.b.size)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	return (free(stk.a.stack), free(stk.b.stack), free(check), EXIT_SUCCESS);
}
