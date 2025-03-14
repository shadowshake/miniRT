/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayzand <cbayzand@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:34:15 by cbayzand          #+#    #+#             */
/*   Updated: 2024/04/18 13:41:08 by cbayzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printint(int num)
{
	int	len;

	len = 0;
	if (num == -2147483648)
		len += ft_printstr("-2147483648");
	else if (num < 0)
	{
		len += ft_printchar('-');
		len += ft_printint(-num);
	}
	else if (num >= 10)
	{
		len += ft_printint(num / 10);
		len += ft_printchar(num % 10 + '0');
	}
	else
		len += ft_printchar(num + '0');
	return (len);
}
