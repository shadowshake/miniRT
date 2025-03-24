/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayzand <cbayzand@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:34:32 by cbayzand          #+#    #+#             */
/*   Updated: 2024/04/18 13:41:46 by cbayzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* used ft_isspace to detect spaces */
char	*white_space_loop(char *line, char *temp)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	while (line[i])
	{
		if (ft_isspace(line[i]))
		{
			while (ft_isspace(line[i]))
				i++;
			if (!line[i])
				break ;
			temp[j++] = ' ';
		}
		else
			temp[j++] = line[i++];
	}
	temp[j] = '\0';
	return (temp);
}

char	*white_space(char *line)
{
	char	*temp;

	temp = malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (!temp)
		return (NULL);
	temp = white_space_loop(line, temp);
	if (temp[0] == '\0')
		return (NULL);
	free(line);
	return (temp);
}

int	read_file(int fd, t_scene *scene, int *shape_index)
{
	char	*line;

	init_shapes(scene);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line = white_space(line);
		if (!line)
			continue ;
		if (!store_info(scene, line, shape_index))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	close (fd);
	(void)scene;
	return (1);
}

/* count the numbers of each shape in the .rt file */
int	count_shapes(char *file, t_scene *scene)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (print_error("Failed to open file"));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strncmp(line, "sp", 2))
			scene->sp_qty ++;
		else if (ft_strncmp(line, "pl", 2))
			scene->pl_qty ++;
		else if (ft_strncmp(line, "cy", 2))
			scene->cy_qty ++;
		free(line);
	}
	close(fd);
	return (1);
}

int	parse(char *file, t_scene *scene)
{
	int	fd;
	int	shape_index[3];

	if (ft_strncmp(file + (ft_strlen(file) - 3), ".rt", 3))
	{
		print_error("Invalid file type, ensure this is .rt file");
		return (1);
	}
	shape_index[0] = 0;
	shape_index[1] = 0;
	shape_index[2] = 0;
	count_shapes(file, scene);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (print_error("Failed to open file"));
	if (!read_file(fd, scene, shape_index))
		return (0);
	return (1);
}
