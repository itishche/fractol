/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 12:04:07 by itishche          #+#    #+#             */
/*   Updated: 2019/03/26 12:04:09 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_fractol.h"

void		ft_bzero(void *str, size_t n)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)str;
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
}

int				ft_strcmp(char *s1, char *s2)
{
	size_t i;

	i = 0;
	while (s1[i] == s2[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	write(1, s, i);
}
