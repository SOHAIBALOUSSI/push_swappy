/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-alo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:30:38 by sait-alo          #+#    #+#             */
/*   Updated: 2023/12/24 13:30:40 by sait-alo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include "get_next_line.h"

static void	hold(char **buffer, char **tmp, char **tmp2)
{
	*tmp2 = ft_strjoin(*tmp, *buffer);
	free(*tmp);
	*tmp = ft_strjoin(*tmp2, "");
	free(*tmp2);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	int		i;
	char	*tmp;
	char	*tmp2;

	if (fd < 0)
		return (0);
	buffer = (char *)malloc(2 * sizeof(char));
	if (!buffer)
		return (NULL);
	i = read(fd, buffer, 1);
	if (i <= 0 || buffer[0] == '\0')
		return (free(buffer), NULL);
	buffer[1] = '\0';
	tmp = ft_strdup("");
	while (i > 0 && *buffer != '\n')
	{
		hold(&buffer, &tmp, &tmp2);
		i = read(fd, buffer, 1);
	}
	if (*buffer == '\n')
		return (tmp2 = ft_strjoin(tmp, buffer), free(buffer), free(tmp), tmp2);
	return (free(buffer), tmp);
}
