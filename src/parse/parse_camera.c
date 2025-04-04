/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:50:39 by shulee            #+#    #+#             */
/*   Updated: 2025/03/23 18:50:40 by shulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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

	cood = ft_split(line[1], ',');
	if (!cood)
		return (0);
	vec = ft_split(line[2], ',');
	if (!vec)
		return (0);
	scene->camera.orient = vec3(str_to_float(cood[0]), str_to_float(cood[1]), str_to_float(cood[2]));
	scene->camera.orient = vec3(str_to_float(vec[0]), str_to_float(vec[1]), str_to_float(vec[2]));
	scene->camera.fov = ft_atoi(line[3]);
	return (1);
}
