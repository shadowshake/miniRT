/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:19:21 by shulee            #+#    #+#             */
/*   Updated: 2025/05/05 16:19:36 by shulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void	rendersphere(t_sphere	*sp, t_scene *scene)
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