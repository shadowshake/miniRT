#include "../../inc/miniRT.h"

int	init_sphere(t_scene *scene, char **line, int *shape_index)
{
	t_sphere	*sp;
	char		**cood;
	char		**color;

	cood = ft_split(line[1], ',');
	if (!cood)
		return (0);
	color = ft_split(line[3], ',');
	if (!color)
		return (free_strs(cood));
	sp = &(scene->spheres[shape_index[0]]);
	sp->pos[0] = str_to_float(cood[0]);
	sp->pos[1]  = str_to_float(cood[1]);
	sp->pos[2] = str_to_float(cood[2]);
	sp->dia = str_to_float(line[2]);
	sp->colour[0] = ft_atoi(color[0]);
	sp->colour[1] = ft_atoi(color[1]);
	sp->colour[2] = ft_atoi(color[2]);
	free_strs(cood);
	free_strs(color);
	return (1);
}
