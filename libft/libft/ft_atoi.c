/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayzand <cbayzand@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:06:05 by cbayzand          #+#    #+#             */
/*   Updated: 2024/03/20 10:56:09 by cbayzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	value;
	int	sign;

	sign = 1;
	value = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\f' || *str == '\r' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		value = value * 10 + *str - '0';
		str++;
	}
	return (value * sign);
}
