/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-alo <sait-alo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 07:58:09 by sait-alo          #+#    #+#             */
/*   Updated: 2024/04/30 07:58:17 by sait-alo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exit_error(char *error_msg, char *str, char *args, int *array)
{
	if (error_msg)
		write(2, error_msg, ft_strlen(error_msg));
	if (str)
		free(str);
	if (args)
		free(args);
	if (array)
		free(array);
	exit(-1);
}

void	exit_free(char *error_msg, int *a, int *b)
{
	if (error_msg)
		write(2, error_msg, ft_strlen(error_msg));
	if (a)
		free(a);
	if (b)
		free(b);
	exit(-1);
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

int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->top)
	{
		if (a->stack[i] < a->stack[i + 1])
			return (-1);
		i++;
	}
	return (0);
}

int	is_void(char *av)
{
	int	i;

	i = -1;
	while (av[++i])
		if (av[i] != ' ')
			return (0);
	return (1);
}
