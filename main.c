
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
	get_nums(args, stacks);

	int j = 0;
	int i = 0;
	push_b(&stacks->a, &stacks->b);
	push_b(&stacks->a, &stacks->b);
	
	int top = stacks->a.top;
	while (stacks->a.size--)
		ft_printf("stack a : %d\n", stacks->a.stack[top++]);
	push_b(&stacks->a, &stacks->b);
	// ft_printf("b size :%d\n", stacks->b.size);
	while (i < stacks->b.size)
		ft_printf("stack b : %d\n", stacks->b.stack[i++]);
	

	free(stacks->a.stack);
	free(args);
}


int	main(int ac, char **av)
{
	t_push_swap	stacks;

	int i = 0;
	stacks.a = (t_stack){0};
	stacks.b = (t_stack){0};
	if (ac == 1)
		return (-1);
	if (ac > 1)
	{
		process_input(&stacks, ac, av);
		
	}

	return (0);
}
