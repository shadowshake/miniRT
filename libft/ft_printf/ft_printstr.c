/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayzand <cbayzand@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:33:40 by cbayzand          #+#    #+#             */
/*   Updated: 2024/04/18 13:41:34 by cbayzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
	{
		len += ft_printstr("(null)");
		return (len);
	}
	while (str[len])
	{
		write (1, &str[len], 1);
		len++;
	}
	return (len);
}
