/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayzand <cbayzand@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:46:49 by cbayzand          #+#    #+#             */
/*   Updated: 2024/04/18 11:46:51 by cbayzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != (char)c && s[i])
		i++;
	if (s[i] == (char)c)
		return ((char *)(s + i));
	else
		return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_str = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new_str == NULL)
		return (NULL);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}

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
