#include "miniRT.h"

int main(int argc, char **argv)
{
	t_scene	*scene;

	scene = ft_calloc(sizeof(t_scene), 1);
	if (argc != 2)
	{
		printf("Error\nInput a single .rt file\n");
		free(scene);
		return (1);
	}
	if (parse(argv[1], scene))
		return (1);
	free(scene);
	return (0);
}