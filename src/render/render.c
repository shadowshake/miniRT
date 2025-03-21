#include "../../inc/miniRT.h"

void	render(t_scene *scene)
{

	
	mlx_put_image_to_window(scene->mlx, scene->win, scene->img, 0, 0);
	mlx_loop(scene->mlx);
}