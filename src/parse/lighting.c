/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayzand <cbayzand@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:34:32 by cbayzand          #+#    #+#             */
/*   Updated: 2024/04/18 13:41:46 by cbayzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_ambient_args(char **line)
{
	int	i;
	int	light_ratio;

	i = 0;
	while (line[i])
		i++;
	if (i > 3)
		return (print_error("Too many arguments in ambient"));
	if (i < 3)
		return (print_error("Not enough arguments in ambient"));
	light_ratio = ft_atoi(line[1]);
	if (light_ratio > 1 || light_ratio < 0)
		return (print_error("Ambient light ratio not within range 0 to 1"));
	if (!check_colour_range(line[2]))
		return (0);
	return (1);
}

int	init_ambient(t_scene *scene, char **line)
{
	int		i;
	char	**str;

	if (!check_ambient_args(line))
		return (0);
	scene->ambient.ratio = str_to_float(line[1]);
	str = ft_split(line[2], ',');
	i = 0;
	while (i < 3)
	{
		scene->ambient.colour[i] = ft_atoi(str[i]);
		i++;
	}
	free(str);
	return (1);
}

/*
int init_light(t_scene *scene, char **line)
{

}
*/