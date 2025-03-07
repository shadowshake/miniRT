/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayzand <cbayzand@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:52:00 by cbayzand          #+#    #+#             */
/*   Updated: 2024/03/21 14:13:16 by cbayzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str);
void	*ft_bzero(void *str, unsigned int n);
void	*ft_calloc(unsigned int nitems, unsigned int size);
int		ft_isalnum(int x);
int		ft_isalpha(int x);
int		ft_isascii(int x);
int		ft_isdigit(int x);
int		ft_isprint(int x);
char	*ft_itoa(int n);
void	*ft_memchr(const void *str, int c, unsigned int n);
int		ft_memcmp(const void *str1, const void *str2, unsigned int n);
void	*ft_memcpy(void *dest, const void *src, unsigned int n);
void	*ft_memmove(void *str1, const void *str2, unsigned int n);
void	*ft_memset(void *str, int c, unsigned int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *src);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlcat(char *dst, const char *src, unsigned int size);
int		ft_strlcpy(char *dst, const char *src, unsigned int len);
int		ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *str1, const char *str2, unsigned int n);
char	*ft_strnstr(const char *str1,	const char *str2, size_t len);
char	*ft_strrchr(const char *str, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_toupper(int x);
int		ft_tolower(int x);
void	ft_strcpy(char *dest, const char *src);

#endif
