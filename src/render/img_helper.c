/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:15:48 by shulee            #+#    #+#             */
/*   Updated: 2024/05/29 16:16:43 by shulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void	mlx_draw(t_scene *data, int x, int y, int color)
{
	char	*dst;

	if (x <= WINHEIGHT && x >= -(WINHEIGHT)
		&& y <= (WINWIDTH) && y >= -(WINWIDTH))
	{
		dst = data->addr + (y * data->line_length
				+ x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int	mlx_exit(int keycode, t_scene *mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(1);
	}
	else if (keycode < 0)
		exit(1);
	return (0);
}