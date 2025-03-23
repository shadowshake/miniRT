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

void	render(t_scene *scene)
{
	mlx_put_image_to_window(scene->mlx, scene->win, scene->img, 0, 0);
	mlx_loop(scene->mlx);
}
