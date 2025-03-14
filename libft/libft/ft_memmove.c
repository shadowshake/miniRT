/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayzand <cbayzand@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:51:44 by cbayzand          #+#    #+#             */
/*   Updated: 2024/03/15 10:53:44 by cbayzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, unsigned int n)
{
	char				*dest;
	char				*src;
	unsigned int		i;

	dest = (char *)str1;
	src = (char *)str2;
	i = 0;
	if (dest < src)
	{
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			dest[n - 1] = src[n - 1];
			n--;
		}
	}
	return (str1);
}
