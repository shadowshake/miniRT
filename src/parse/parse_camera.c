#include "../../inc/miniRT.h"

int	check_cam_input(char **line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	if (i != 3)
		return (print_error("Wrong number of arguments in camera!"));
	return (1);
}

int init_camera(t_scene *scene, char **line)
{
	char		**cood;
	char		**vec;
	t_camera	*cam;

	cood = ft_split(line[0], ',');
	if (!cood)
		return (0);
	vec = ft_split(line[1], ',');
	if (!vec)
	{
		free_strs(cood);
		return (0);
	}
	cam = &(scene->camera);
	cam->pos[0] = str_to_float(cood[0]);
	cam->pos[1] = str_to_float(cood[1]);
	cam->pos[2] = str_to_float(cood[2]);
	cam->vector[0] = str_to_float(vec[0]);
	cam->vector[1] = str_to_float(vec[1]);
	cam->vector[2] = str_to_float(vec[2]);
	cam->fov = ft_atoi(line[2]);
	return (1);
}
