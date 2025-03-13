/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayzand <cbayzand@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:37:25 by cbayzand          #+#    #+#             */
/*   Updated: 2024/03/15 11:41:03 by cbayzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != c && str[i])
				i++;
			if (!str[i])
				break ;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		word_len;
	int		i;

	str = (char **)malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!str)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			str[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	str[i] = NULL;
	return (str);
}
