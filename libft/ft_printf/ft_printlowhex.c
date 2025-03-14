/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlowhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayzand <cbayzand@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:41:21 by cbayzand          #+#    #+#             */
/*   Updated: 2024/04/18 13:41:23 by cbayzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printlowhex(unsigned int num)
{
	int		len;
	int		j;
	int		temp;
	char	hexa_num[100];

	len = 0;
	if (num == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	while (num != 0)
	{
		temp = num % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 87;
		hexa_num[len++] = temp;
		num = num / 16;
	}
	j = len;
	while (j-- > 0)
		write (1, &hexa_num[j], 1);
	return (len);
}
