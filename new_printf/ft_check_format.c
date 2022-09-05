/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:00:08 by tidminta          #+#    #+#             */
/*   Updated: 2020/04/11 19:24:44 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_get_flag(const char *s, int *index, t_infos_ *struct_ptr_)
{
	while (s[*index] && s[*index] != '%')
		*index += 1;
	if (s[*index] == '%')
	{
		*index += 1;
		if (s[*index] == '0')
			struct_ptr_->flag_zero = 1;
		else
			struct_ptr_->flag_zero = 0;
		if (s[*index] == '-')
			struct_ptr_->flag_moins  = 1;
		else
			struct_ptr_->flag_moins = 0;
	}
}

int	ft_get_width(const char *s, int *index)
{
	unsigned int	j;
	int				width;
	char			*alloc;
	size_t			len;

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
	free(alloc);
	if (width)
		return (width);
	return (0);
}

int	ft_get_precis(const char *s, int *index)
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
