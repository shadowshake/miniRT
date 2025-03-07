/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayzand <cbayzand@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:04:05 by cbayzand          #+#    #+#             */
/*   Updated: 2024/03/15 11:05:00 by cbayzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, unsigned int n)
{
	const char		*s;

	s = str;
	while (n-- > 0)
	{
		if (*s == (char) c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
