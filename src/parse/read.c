#include "miniRT.h"

int read_file(char *file)
{
	int	fd;
	char *line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nFailed to open file\n");
		return (1);
	}
	
	close(fd);
}

int parse(char *file, t_scene scene)
{
	char **strs;

	strs = read_file(file);
	return (0);
}