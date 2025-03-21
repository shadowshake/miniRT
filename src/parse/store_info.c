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

float	str_to_float(char *str)
{
	float	sum;
	float	prec;
	float	div;
	float	sign;

	prec = 0.0;
	div = 1.0;
	sign = 1.0;
	if (str && str[0] == '-')
		sign *= -1.0;
	sum = (float)ft_atoi(str);
	while (*str && *str != '.')
		str++;
	if (*str++ == '.')
	{
		while (*str >= '0' && *str <= '9')
		{
			div *= 10.0;
			prec += (*str - '0') / div;
			str++;
		}
		sum += prec * sign;
	}
	return (sum);
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
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ' && line[i] != ','
			&& line[i] != '.' && line[i] != '-')
			return (print_error("You added a weird character to the rt file"));
		i++;
	}
	return (1);
}

int	store_info(t_scene *scene, char *line)
{
	char	**str;

	if (!check_line(line))
		return (0);
	str = ft_split(line, ' ');
	if (str[0][0] == 'A')
		return (init_ambient(scene, str));
	/*
	else if (str[0] == 'L')
		return (init_light(scene, str));
	*/
	else if (str[0][0] == 'C')
		return (init_camera(scene, str));
	else if (ft_strncmp(str[0], "sp", 2))
		return (init_sphere(scene, str));
	/*
	else if (ft_strncmp(str[0], "pl", 2))
		return (init_plane(scene, str));
	else if (ft_strncmp(str[0], "cy", 2))
		return (init_cylinder(scene, str));
	*/
	else
		return (print_error("You passing weird stuff in rt file"));
}
