/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayzand <cbayzand@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:37:19 by cbayzand          #+#    #+#             */
/*   Updated: 2024/04/18 13:40:27 by cbayzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pformat(va_list args, char str)
{
	int	len;

	len = 0;
	if (str == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (str == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (str == 'p')
		len += ft_printhex(va_arg(args, size_t));
	else if (str == 'd' || str == 'i')
		len += ft_printint(va_arg(args, int));
	else if (str == 'u')
		len += ft_printunsignedint(va_arg(args, unsigned int));
	else if (str == 'x')
		len += ft_printlowhex(va_arg(args, unsigned int));
	else if (str == 'X')
		len += ft_printuphex(va_arg(args, unsigned int));
	else
		len += ft_printchar('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	va_start(args, s);
	len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += pformat(args, s[i + 1]);
			i++;
		}
		else
			len += ft_printchar(s[i]);
		i++;
	}
	va_end(args);
	return (len);
}
