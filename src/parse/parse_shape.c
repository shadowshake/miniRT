#include "../../inc/miniRT.h"

int	init_sphere(t_scene *scene, char **line)
{
	t_sphere	*sp;
	char		**cood;
	char		**color;

	cood = ft_split(line[0]);
	if (!cood)
		return (0);
	color = ft_split(line[2]);
	if (!color)
	{
		free_strs(cood);
		return (0);
	}
	sp = scene->sphere;
	sp->pos[0] = str_to_float(cood[0]);
	sp->pos[1]  = str_to_float(cood[1]);
	sp->pos[2] = str_to_float(cood[2]);
	sp->
}
