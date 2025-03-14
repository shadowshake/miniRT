/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayzand <cbayzand@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:53:57 by cbayzand          #+#    #+#             */
/*   Updated: 2024/03/15 10:55:25 by cbayzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dst, const char *src, unsigned int len)
{
	unsigned int	srclen;
	char			*source;

	source = (char *)src;
	srclen = ft_strlen(source);
	if (srclen + 1 < len)
		ft_memcpy(dst, source, srclen + 1);
	else if (len != 0)
	{
		ft_memcpy(dst, source, len - 1);
		dst[len - 1] = '\0';
	}
	return (srclen);
}
