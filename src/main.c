#include "miniRT.h"

int main(int argc, char **argv)
{
	t_scene	scene;
	if (argc != 2)
	{
		printf("Error\nInput a single .rt file\n");
		return (1);
	}
	if (parse(argv[1], &scene))
		return (1);
	return (0);
}