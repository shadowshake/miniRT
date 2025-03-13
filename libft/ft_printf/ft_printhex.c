/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayzand <cbayzand@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:36:56 by cbayzand          #+#    #+#             */
/*   Updated: 2024/04/18 13:40:51 by cbayzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	makehex(size_t ptr)
{
	int			len;
	int			j;
	size_t		temp;
	char		hexa_num[100];

	len = 0;
	while (ptr != 0)
	{
		temp = ptr % 16;
		if (temp < 10)
			temp += 48;
		else
			temp += 87;
		hexa_num[len++] = temp;
		ptr /= 16;
	}
	j = len;
	while (j-- > 0)
		write (1, &hexa_num[j], 1);
	return (len);
}

int	ft_printhex(size_t ptr)
{
	int	len;

	len = 2;
	write(1, "0x", 2);
	if (ptr == 0)
	{
		write (1, "0", 1);
		return (3);
	}
	len += makehex(ptr);
	return (len);
}
