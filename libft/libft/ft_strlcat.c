/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayzand <cbayzand@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:55:41 by cbayzand          #+#    #+#             */
/*   Updated: 2024/03/15 10:56:09 by cbayzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, unsigned int size)
{
	unsigned int	dstlen;
	unsigned int	srclen;
	unsigned int	i;
	char			*source;

	source = (char *)src;
	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(source);
	if (dstlen < size - 1 && size > 0)
	{
		while (i < srclen && dstlen + i < size - 1)
		{
			dst[dstlen + i] = source[i];
			i++;
		}
		dst[dstlen + i] = '\0';
	}
	else if (dstlen >= size)
		dstlen = size;
	return (dstlen + srclen);
}
