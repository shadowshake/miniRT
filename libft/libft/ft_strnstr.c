/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayzand <cbayzand@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:05:14 by cbayzand          #+#    #+#             */
/*   Updated: 2024/03/15 11:05:51 by cbayzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1,	const char *str2, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (!str2 || str2[0] == '\0')
		return ((char *)str1);
	while (str1[i] != '\0' && i < len)
	{
		n = 0;
		while (str1[i + n] == str2[n] && (i + n < len))
		{
			if (str2[n + 1] == '\0')
			{
				return ((char *)(str1 + i));
			}
			n++;
		}
		i++;
	}
	return (NULL);
}
