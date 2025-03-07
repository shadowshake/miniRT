/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayzand <cbayzand@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:07:47 by cbayzand          #+#    #+#             */
/*   Updated: 2024/03/15 11:08:38 by cbayzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		n;
	char	*dest;
	int		i;

	i = 0;
	n = ft_strlen(src);
	dest = (char *) malloc (sizeof(char) * (n + 1));
	if (dest == NULL)
	{
		return (NULL);
	}
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
