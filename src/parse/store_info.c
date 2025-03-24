/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayzand <cbayzand@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:34:32 by cbayzand          #+#    #+#             */
/*   Updated: 2024/04/18 13:41:46 by cbayzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* malloc an array for each shape */
int	init_shapes(t_scene *scene)
{
	scene->spheres = ft_calloc((scene->sp_qty + 1), sizeof (t_sphere));
	if (!scene->spheres)
		return (0);
	scene->planes = ft_calloc((scene->pl_qty + 1), sizeof (t_plane));
	if (!scene->planes)
		return (0);
	scene->cylinders = ft_calloc((scene->cy_qty + 1), sizeof (t_cylinder));
	if (!scene->cylinders)
		return (0);
	return (1);
}

int	check_colour_range(char *str)
{
	char	**split_chars;
	int		colour_value;
	int		i;

	i = 0;
	split_chars = ft_split(str, ',');
	while (split_chars[i])
	{
		colour_value = ft_atoi(split_chars[i]);
		if (colour_value > 255 || colour_value < 0)
		{
			free(split_chars);
			return (print_error("colour range not within 0 - 255 range"));
		}
		i++;
	}
	free(split_chars);
	if (i != 3)
		return (print_error("Invalid number of arguments in colour range"));
	return (1);
}

//checks for non-number character in line
int	check_line(char *line)
{
	int	i;

	i = 1;
	line = ft_strchr(line, ' ');
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ' && line[i] != ','
			&& line[i] != '.' && line[i] != '-')
			return (print_error("You added a weird character to the rt file"));
		i++;
	}
	return (1);
}

int	store_info(t_scene *scene, char *line, int *shape_index)
{
	char	**str;

	if (!check_line(line))
		return (0);
	str = ft_split(line, ' ');
	if (str[0][0] == 'A')
		return (init_ambient(scene, str));
	else if (str[0][0] == 'L')
		return (init_light(scene, str));
	else if (str[0][0] == 'C')
		return (init_camera(scene, str));
	else if (!ft_strncmp(str[0], "sp", 2))
		return (init_sphere(scene, str, shape_index));
	else if (!ft_strncmp(str[0], "pl", 2))
		return (init_plane(scene, str, shape_index));
	else if (!ft_strncmp(str[0], "cy", 2))
		return (init_cylinder(scene, str, shape_index));
	else
		return (print_error("You passing weird stuff in rt file"));
}
