/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayzand <cbayzand@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:33:24 by cbayzand          #+#    #+#             */
/*   Updated: 2024/04/18 13:33:28 by cbayzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

int	ft_printlowhex(unsigned int num);
int	ft_printchar(int c);
int	ft_printint(int num);
int	ft_printstr(char *str);
int	ft_printuphex(unsigned int num);
int	ft_printhex(size_t ptr);
int	ft_printunsignedint(unsigned int num);
int	ft_printf(const char *s, ...);

#endif