/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsignedint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayzand <cbayzand@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:34:32 by cbayzand          #+#    #+#             */
/*   Updated: 2024/04/18 13:41:46 by cbayzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunsignedint(unsigned int num)
{
	int	len;

	len = 0;
	if (num >= 10)
	{
		len += ft_printunsignedint(num / 10);
		len += ft_printchar(num % 10 + '0');
	}
	else
		len += ft_printchar(num + '0');
	return (len);
}
