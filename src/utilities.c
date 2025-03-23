/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayzand <cbayzand@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:34:32 by cbayzand          #+#    #+#             */
/*   Updated: 2024/04/18 13:41:46 by cbayzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	print_error(char *str)
{
	printf("Error\n%s\n", str);
	return (0);
}

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

/*
int	*init_array(int *input, int len)
{
	int i;

	i = 0;
	while (i < len)
		input[i] = 0;
	return (input);
}
*/

int	free_strs(char **strs)
{
	int	i;

	i = -1;
	if (strs)
	{
		while (strs[++i])
			free(strs[i]);
		free(strs);
	}
	return (0);
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\f' || c == '\r'
		|| c == 'v' || c == ' ')
		return (1);
	return (0);
}