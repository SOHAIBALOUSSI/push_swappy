
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
	int tmp;
	tmp = count_nums(args, ' ');
	stacks->a.size = tmp;
	get_nums(args, stacks);
	
	stacks->a.size = tmp;

	// rotate(&stacks->a, 'a');
	// while (stacks->a.top >= 0)
	// 	ft_printf("stk a : %d\n", stacks->a.stack[stacks->a.top--]);
	// while (stacks->b.top >= 0)
	// 	ft_printf("stk b : %d\n", stacks->b.stack[stacks->b.top--]);
	
	free(stacks->a.stack);
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
		
	}

	return (0);
}
