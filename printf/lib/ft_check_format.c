/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:00:08 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/29 22:41:07 by tidminta         ###   ########.fr       */
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

void		ft_get_flag(char *s, int *index, t_infos_ *struct_ptr_)
{
	while (s[*index] && s[*index] != '%')
		*index += 1;
	if (s[*index] == '%')
	{
		*index += 1;
		struct_ptr_->flag_zero = (s[*index] == '0') ? 1 : 0;
		struct_ptr_->flag_moins = (s[*index] == '-') ? 1 : 0;
	}
	// printf("[fin ft_get_flags]\n[*index] = [%i]\n", *index);
}

int			ft_get_width(char *s, int *index)
{
	unsigned int	j;
	int				width;
	char			*alloc;
	size_t			len;

	// printf("[debut ft_get_width]\n[*index] = [%i]\n", *index);
	width = 0;
	len = 0;
	j = *index;
	while (s[*index] && ft_isdigit(s[*index])
		&& (s[*index != '.'] || !(ft_check_conv_spe(s[*index]))))
	{
		*index += 1;
		len++;
	}
	if (!(alloc = ft_substr(s, j, len)))
		return (-1);
	width = ft_atoi(alloc);
	// printf("[fin ft_get_width]\n[*index] = [%i]\n[len] = [%zi]\n", *index, len);
	return (width);
	// }
	return (0);
}

int			ft_get_precis(char *s, int *index)
{
	unsigned int	j;
	int				precis;
	char			*alloc;
	size_t			len;

	// printf("[debut ft_get_precis]\n[*index] = [%i]\n", *index);
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
