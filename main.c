
#include "push_swap.h"

char *join_args(int ac, char **av)
{
	int		i;
	char	*args;
	char	*tmp;

	i = 1;
	args = NULL;
	tmp = NULL;
	while (i < ac)
	{
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

void process_input(t_push_swap *stacks, int ac, char **av)
{
	char *args;

	args = join_args(ac, av);
	if (!args)
		exit_error("Error\nFailed to join Arguments!", NULL, NULL, NULL);
	check_input(args);
	stacks->a.size = count_nums(args, ' ');
	get_nums(args, stacks);
	stacks->a.top = stacks->a.size - 1;
	stacks->b.stack = malloc(stacks->a.size * sizeof(int));

	while (stacks->a.top >= 0)
		ft_printf("stk a : %d\n", stacks->a.stack[stacks->a.top--]);
	
	free(stacks->a.stack);
	free(stacks->b.stack);

	free(args);
}


int	main(int ac, char **av)
{
	t_push_swap	stacks;

	int i = 0;
	stacks.a = (t_stack){0};
	stacks.b = (t_stack){0};
	stacks.b.top = -1;

	if (ac == 1)
		return (-1);
	if (ac > 1)
	{
		process_input(&stacks, ac, av);
		if (is_sorted() == 0)
			return(-1);
		if (stacks.a.size <= 5)
			performe_easy_sort();
		else
			performe_sorting_hack();
	}
	return (0);
}
