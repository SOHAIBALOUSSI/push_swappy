/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-alo <sait-alo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 07:57:19 by sait-alo          #+#    #+#             */
/*   Updated: 2024/04/30 07:57:22 by sait-alo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	deja_vu(int *nums, int curr_size, int size)
{
	while (--size > curr_size)
	{
		if (nums[curr_size] == nums[size])
		{
			write(2, "Error\n", 7);
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
			exit_error("Error\n", s, NULL, NULL);
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
			exit_error("Error\n", str, arg, nums);
	}
	return (free(str), (result * s));
}

void	get_nums(char *arg, t_push_swap *stack)
{
	int		i;
	int		j;
	int		curr_size;
	char	*tmp;

	stack->a.stack = malloc(stack->a.size * sizeof(int));
	if (!stack->a.stack)
		exit(-1);
	i = -1;
	curr_size = stack->a.size;
	while (arg[++i] && curr_size >= 0)
	{
		tmp = NULL;
		while (arg[i] && arg[i] == ' ')
			i++;
		if (!arg[i])
			exit_error(NULL, NULL, arg, NULL);
		j = i;
		while (arg[i] && arg[i] != ' ')
			i++;
		tmp = ft_substr(arg, j, i - j);
		stack->a.stack[--curr_size] = fatoi(tmp, stack->a.stack, arg);
		if (deja_vu(stack->a.stack, curr_size, stack->a.size) == -1)
			exit_error(NULL, NULL, arg, stack->a.stack);
	}
}
