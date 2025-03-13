/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayzand <cbayzand@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:09:20 by cbayzand          #+#    #+#             */
/*   Updated: 2024/03/20 11:35:50 by cbayzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*return_string;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((size_t) ft_strlen(s) < len)
		len = ft_strlen(s);
	return_string = (char *)malloc(sizeof(char) * (len + 1));
	if (return_string == NULL)
		return (NULL);
	while (s[i])
	{
		if (j < len && i >= start)
		{
			return_string[j] = s[i];
			j++;
		}
		i++;
	}
	return_string[j] = '\0';
	return (return_string);
}
