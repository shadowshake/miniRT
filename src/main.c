#include "minirt.h"

int check_arg(char **argv, int argc)
{
	if (argc != 2)
	{
		printf("Error\nInput a single .rt file")
		return (1);
	}
}

int main(int argc, char **argv)
{
	if(check_arg(argv, argc))
		return (1);
	
}