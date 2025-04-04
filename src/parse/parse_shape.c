/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:51:52 by shulee            #+#    #+#             */
/*   Updated: 2025/03/23 18:51:54 by shulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* set the coordinate and colour of each shape */
/* since both of these attributes are common within all 3 */
static int	set_common(t_vec3 *pos, int *colour, char *line1, char *line2)
{
	char	**cood;
	char	**color;

	cood = ft_split(line1, ',');
	if (!cood)
		return (0);
	color = ft_split(line2, ',');
	if (!color)
		return (free_strs(cood));
	*pos = vec3(str_to_float(cood[0]), str_to_float(cood[1]), str_to_float(cood[2]));
	colour[0] = ft_atoi(color[0]);
	colour[1] = ft_atoi(color[1]);
	colour[2] = ft_atoi(color[2]);
	free_strs(cood);
	free_strs(color);
	return (1);
}

int	init_sphere(t_scene *scene, char **line, int *shape_index)
{
	t_sphere	*sp;

	sp = &(scene->spheres[shape_index[0]]);
	if (!set_common(&sp->pos, sp->colour, line[1], line[3]))
		return (0);
	sp->dia = str_to_float(line[2]);
	return (++shape_index[0]);
}

int	init_plane(t_scene *scene, char **line, int *shape_index)
{
	t_plane	*pl;
	char	**vec;

	pl = &(scene->planes[shape_index[1]]);
	if (!set_common(&pl->point, pl->colour, line[1], line[3]))
		return (0);
	vec = ft_split(line[2], ',');
	if (!vec)
		return (0);
	pl->vector = vec3(str_to_float(vec[0]), str_to_float(vec[1]), str_to_float(vec[2]));
	free_strs(vec);
	return (++shape_index[1]);
}

int	init_cylinder(t_scene *scene, char **line, int *shape_index)
{
	t_cylinder	*cy;
	char		**vec;

	cy = &(scene->cylinders[shape_index[2]]);
	if (!set_common(&cy->pos, cy->colour, line[1], line[5]))
		return (0);
	vec = ft_split(line[2], ',');
	if (!vec)
		return (0);
	cy->dia = str_to_float(line[3]);
	cy->height = str_to_float(line[4]);
	cy->axis = vec3(str_to_float(vec[0]), str_to_float(vec[1]), str_to_float(vec[2]));
	free_strs(vec);
	return (++shape_index[2]);
}