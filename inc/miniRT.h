#ifndef MINIRT_H
# define MINIRT_H

# include "libft/libft.h"
# include "libmlx/mlx.h"

# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_sphere
{
	float	*center[3];
	float	dia;
	int		*colour[3];
}   t_sphere;

typedef struct s_plane
{
	float	*point[3];
	float	*vector[3];
	int		*colour[3];
}	t_plane;

typedef struct s_cylinder
{
	float	*center[3];
	float	*vector[3];
	float	dia;
	float	height;
	int		*colour[3];
}	t_cylinder;

typedef struct s_light
{
	float	*pos[3];
	float	bright;
}	t_light;

typedef struct s_ambient
{
	float	ratio;
	int		*colour;
}	t_ambient;

typedef struct s_scene
{

	t_sphere	*spheres;
	t_plane		*planes;
	t_cylinder	*cylinders;
}   t_scene;



#endif