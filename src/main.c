/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayzand <cbayzand@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:34:32 by cbayzand          #+#    #+#             */
/*   Updated: 2024/04/18 13:41:46 by cbayzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

static void	scene_init(t_scene *scene)
{
	scene -> mlx = mlx_init();
	scene -> win = mlx_new_window(scene -> mlx, 800, 800, "raytrace");
	scene -> img = mlx_new_image(scene -> mlx, 800, 800);
	scene -> addr = mlx_get_data_addr(scene -> img, &(scene -> bits_per_pixel),
			&(scene -> line_length), &(scene -> endian));
	mlx_hook(scene -> win, 2, 1L << 0, mlx_exit, scene);
	mlx_hook(scene -> win, 17, 0, mlx_exit, scene);
}

int	main(int argc, char **argv)
{
	t_scene	*scene;

	scene = ft_calloc(sizeof(t_scene), 1);
	if (argc != 2)
	{
		print_error("Input a single .rt file");
		free(scene);
		return (1);
	}
	if (!parse(argv[1], scene))
		return (1);
	scene_init(scene);
	render(scene);
	free(scene);
	return (0);
}
