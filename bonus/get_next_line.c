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

#include "checker.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*new;

	i = 0;
	new = (char *)malloc(ft_strlen(s) + 1);
	if (!new)
		return (NULL);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static int	gnl_strchr(const char *s, char c)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*read_line(int fd, char *content, char *buffer)
{
	ssize_t	readed;
	char	*tmp;

	readed = 1;
	while (readed > 0 && !(gnl_strchr(content, '\n')))
	{
		readed = read(fd, buffer, 1);
		if (readed < 0)
		{
			free(buffer);
			return (NULL);
		}
		else if (readed == 0)
			break ;
		if (!content)
			content = ft_strdup("");
		buffer[readed] = '\0';
		tmp = content;
		content = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
	}
	free(buffer);
	return (content);
}

static char	*get_rest(char *line)
{
	ssize_t	i;
	char	*result;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	result = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*result == 0)
	{
		free(result);
		result = NULL;
	}
	line[i + 1] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*content;
	char		*buffer;
	char		*line;

	line = NULL;
	buffer = malloc((2) * sizeof(char));
	if (fd < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = read_line(fd, content, buffer);
	if (!line)
		return (NULL);
	content = get_rest(line);
	return (line);
}
