#include "push_swap.h"

void	exit_error(char *error_msg, char *str, char *args, int *array)
{
	write(2, RED, 8);
	if (error_msg)
		write(2, error_msg, ft_strlen(error_msg));
	if (str)
		free(str);
	if (args)
		free(args);
	if (array)
		free(array);
	exit(EXIT_FAILURE);
}

int	deja_vu(int *nums, int *size)
{
	int i;

	i = -1;
	while (++i < *size - 1)
	{
		if (nums[*size - 1] == nums[i])
		{
			write(2, RED, 8);
			write(2, "Error\n", 7);
			ft_printf("%d is Dublicated\n", nums[*size - 1]);
			return (-1);
		}
	}
	return (0);
}

void	check_input(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if ((!ft_isdigit(s[i]) && (s[i] != '-' && s[i] != '+' && s[i] != ' '))
			|| ((s[i] == '-' || s[i] == '+') && !ft_isdigit(s[i + 1]))
			|| ((s[i] == '-' || s[i] == '+') && ft_isdigit(s[i - 1])))
			exit_error("Error\nInvalid set of Arguments!", s, NULL, NULL);
}

int	fatoi(char *str, int *nums, char *arg)
{
	int			i;
	int			s;
	long		result;

	i = 0;
	s = 1;
	result = 0;
	while (str[i] == ' ' && str[i] >= '\t' && str[i] <= '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i++] - '0');
		if ((result > 2147483647 && s == 1) || (result > 2147483648 && s == -1))
			exit_error("Error\nINT LIMITS REACHED!", str, arg, nums);
	}
 	return (free(str), (result * s));
}

int	count_nums(char *s, char c)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			counter++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (counter);
}

void get_nums(char *arg, t_push_swap *stack)
{
	char	*tmp;
	int		i;
	int		j;

	stack->a.stack = malloc(count_nums(arg, ' ') * sizeof(int));
	stack->b.stack = malloc(count_nums(arg, ' ') * sizeof(int));
	if (!stack->a.stack || !stack->b.stack)
		exit_error("Malloc failed!\n", NULL, NULL, NULL);
	i = -1;
	while (arg[++i])
	{
		tmp = NULL;
		while (arg[i] && arg[i] == ' ')
			i++;
		if (!arg[i])
			return ;
		j = i;
		while (arg[i] && arg[i] != ' ')
			i++;
		tmp = ft_substr(arg, j, i - j);
		stack->a.stack[stack->a.size++] = fatoi(tmp, stack->a.stack, arg);
		if (deja_vu(stack->a.stack, &stack->a.size) == -1)
			exit_error(NULL, NULL, arg, stack->a.stack);
	}
}
