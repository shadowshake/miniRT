/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:51:16 by shulee            #+#    #+#             */
/*   Updated: 2025/03/23 18:51:17 by shulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

/* right now this render only consider the position of the camera and circle */
/* the lightings are not effective yet */
void	rendercircle(t_scene *scene)
{
	int	colorcode;
	int	i;
	int	j;

	colorcode = create_rgb(10, 0, 255);
	printf("colorcode %d\n", colorcode);
	i = 0;
	j = 0;
	while (i < 400)
	{
		while (j < 400)
		{
			mlx_draw(scene, i, j, colorcode);
			j ++ ;
		}
		i ++ ;
		j = 0;
	}
}

void	render(t_scene *scene)
{
	rendercircle(scene);
	mlx_put_image_to_window(scene->mlx, scene->win, scene->img, 0, 0);
	mlx_loop(scene->mlx);
}
