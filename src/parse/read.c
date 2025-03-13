#include "miniRT.h"

char	*white_space_loop(char *line, char *temp)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (line[i] && (line[i] == '\t' || line[i] == '\n' || line[i] == ' '))
		i++;
	while (line[i])
	{
		if (line[i] == '\t' || line[i] == '\n' || line[i] == ' ')
		{
			while (line[i] && (line[i] == '\t' || line[i] == '\n'
					|| line[i] == ' '))
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

int	read_file(int fd, t_scene *scene)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line = white_space(line);
		if (!line)
			continue ;
		/*if(!store_info(scene, line))
		{
			free(line);
			return (1);
		}*/
		printf("line: %s\n", line);
		free(line);
	}
	close (fd);
	(void)scene;
	return (1);
}

int	correct_file(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (ft_strncmp(str + (len - 3), ".rt", 3))
	{
		printf("Error\nInvalid file type, ensure this is .rt file\n");
		return (0);
	}
	else
		return (1);
}

int	parse(char *file, t_scene *scene)
{
	int	fd;

	if (!correct_file(file))
		return (1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nFailed to open file\n");
		return (1);
	}
	if (!read_file(fd, scene))
		return (1);
	return (0);
}
