/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayzand <cbayzand@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:45:35 by cbayzand          #+#    #+#             */
/*   Updated: 2024/04/28 13:26:40 by cbayzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*readfile(int fd, char *buffer, char *remaining_chars)
{
	int		readbytes;
	char	*temp;

	readbytes = 1;
	while (readbytes > 0)
	{
		readbytes = read (fd, buffer, BUFFER_SIZE);
		if (readbytes == 0)
			return (remaining_chars);
		else if (readbytes == -1)
			return (NULL);
		buffer[readbytes] = '\0';
		if (!remaining_chars)
			remaining_chars = ft_strdup("");
		temp = remaining_chars;
		remaining_chars = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (remaining_chars);
}

static char	*edit_line(char *line)
{
	char	*remaining_chars;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (0);
	remaining_chars = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*remaining_chars == '\0')
	{
		free(remaining_chars);
		remaining_chars = NULL;
	}
	line[i + 1] = '\0';
	return (remaining_chars);
}

char	*get_next_line(int fd)
{
	static char	*remaining_chars;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = readfile(fd, buffer, remaining_chars);
	if (line == NULL)
	{
		free(buffer);
		free(remaining_chars);
		remaining_chars = NULL;
		return (NULL);
	}
	remaining_chars = edit_line(line);
	free(buffer);
	return (line);
}
