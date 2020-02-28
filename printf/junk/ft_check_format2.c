/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:00:08 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/28 14:50:34 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include <stdio.h>

char		ft_check_conv_spe(char car)
{
	if (car == 'c' || car == 's' || car == 'p' || car == 'd' || car == 'i'
		|| car == 'o' || car == 'u' || car == 'u' || car == 'x' || car == 'X')
		return (car);
	return (0);
}

size_t		ft_strncopy(char *dst, const char *src, int *start, size_t dstsize)
{
	size_t	j;

	j = 0;
	if (!src || !dst)
		return (0);
	if (dstsize == 0)
		return (*start);
	while (src[*start] && j < dstsize - 1)
	{
		dst[j] = src[*start];
		j++;
		*start += 1;
	}
	dst[j] = '\0';
	return (1);
}

int			ft_get_width(const char *s, int *index)
{
	int				width;
	char			tab[30];
	unsigned int	j;
	size_t			len;

	width = 0;
	len = 0;
	while (s[*index] && s[*index] != '%')
		*index += 1;
	if (s[*index] == '%')
	{
		j = *index + 1;
		while (s[++(*index)] && ft_isdigit(s[*index])
			&& (s[*index != '.'] || !(ft_check_conv_spe(s[*index]))))
			len++;
		ft_strncopy(tab, s, index, len);
		width = ft_atoi(tab);
		return (width);
	}
	return (0);
}
