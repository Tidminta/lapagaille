/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:00:08 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/28 23:53:08 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		ft_check_conv_spe(char car)
{
	if (car == 'c' || car == 's' || car == 'p' || car == 'd' || car == 'i'
		|| car == 'o' || car == 'u' || car == 'u' || car == 'x' || car == 'X')
		return (car);
	return (0);
}

int			ft_get_flag(const char *s, t_infos *struct_ptr)
{
	int i;

	i = 0;
	while (s[i] && s[i] != '%')
	{
		if (s[i] == )
	}
}

int			ft_get_width(const char *s, int *index)
{
	unsigned int	j;
	int				width;
	char			*alloc;
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
		if (!(alloc = ft_substr(s, j, len)))
			return (-1);
		width = ft_atoi(alloc);
		return (width);
	}
	return (0);
}

int				ft_get_precis(const char *s, int *index)
{
	unsigned int	j;
	int				precis;
	char			*alloc;
	size_t			len;

	precis = 0;
	j = *index + 1;
	len = 0;
	alloc = NULL;
	while (s[++(*index)] && ft_isdigit(s[*index])
		&& !(ft_check_conv_spe(s[*index])))
		len++;
	if (len)
	{
		if (!(alloc = ft_substr(s, j, len)))
			return (-1);
	}
	precis = ft_atoi(alloc);
	free(alloc);
	return (precis);
}