/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayzand <cbayzand@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:06:48 by cbayzand          #+#    #+#             */
/*   Updated: 2024/03/15 11:07:35 by cbayzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(unsigned int nitems, unsigned int size)
{
	int		total_size;
	void	*memory;

	total_size = nitems * size;
	memory = malloc(total_size);
	if (memory == NULL)
		return (NULL);
	else
		ft_bzero(memory, total_size);
	return (memory);
}
