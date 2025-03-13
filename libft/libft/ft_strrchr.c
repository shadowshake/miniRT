/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayzand <cbayzand@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:01:06 by cbayzand          #+#    #+#             */
/*   Updated: 2024/03/20 11:36:07 by cbayzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	cmp;

	cmp = (char)c;
	i = ft_strlen(str);
	if (cmp == 0)
		return ((char *)str + i);
	if (cmp < 0)
		return (0);
	while (i >= 0)
	{
		if (str[i] == cmp)
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}
