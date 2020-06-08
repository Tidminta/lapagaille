/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:00:08 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/04 18:54:42 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char		ft_check_conv_spe(char car)
{
	if (car == 'c' || car == 's' || car == 'p' || car == 'd' || car == 'i'
		|| car == 'o' || car == 'u' || car == 'u' || car == 'x' || car == 'X'
			|| car == '%' || car == 'b')
		return (car);
	return (0);
}

void		ft_get_flag(const char *s, t_params_ *p_, t_infos_ *st_)
{
	while (s[p_->index] && s[p_->index] != '%')
		p_->index += 1;
	if (s[p_->index] == '%')
	{
		p_->index += 1;
		while (s[p_->index] && ft_check_flag(s[p_->index]))
		{
			if (!st_->flag_zero)
				st_->flag_zero = (s[p_->index] == '0') ? 1 : 0;
			if (!st_->flag_moins)
				st_->flag_moins = (s[p_->index] == '-') ? 1 : 0;
			if (!st_->flag_diez)
				st_->flag_diez = (s[p_->index] == '#') ? 1 : 0;
			p_->index += 1;
		}
	}
}

int			ft_get_width(const char *s, t_params_ *p_, va_list *lst_ptr)
{
	unsigned int	j;
	int				width;
	char			*alloc;
	size_t			len;

	width = 0;
	len = 0;
	j = p_->index;
	if (s[p_->index] == '*')
	{
		width = va_arg(*lst_ptr, int);
		p_->index += 1;
		return (width);
	}
	while (s[p_->index] && ft_isdigit(s[p_->index])
		&& (s[p_->index != '.'] || !(ft_check_conv_spe(s[p_->index]))))
	{
		p_->index += 1;
		len++;
	}
	if (!(alloc = ft_substr(s, j, len)))
		return (-1);
	width = ft_atoi(alloc);
	free(alloc);
	return (width);
}

static int	ft_get_p2(const char *s, t_params_ *p_, t_infos_ *st_, size_t j)
{
	char	*alloc;
	size_t	len;

	len = 0;
	while (s[++(p_->index)] && ft_isdigit(s[p_->index]) &&
			!(ft_check_conv_spe(s[p_->index])))
		len++;
	if (len)
	{
		alloc = NULL;
		if (!(alloc = ft_substr(s, j, len)))
			return (-1);
		st_->precis = ft_atoi(alloc);
		free(alloc);
	}
	return (1);
}

int			ft_get_p(const char *s, t_params_ *p_, t_infos_ *st_, va_list *lst)
{
	size_t			j;

	j = p_->index + 1;
	if ((p_->index > 0) && s[p_->index] == '.')
	{
		st_->is_precis = 1;
		if (s[(p_->index) + 1] == '*')
		{
			p_->index += 1;
			st_->precis = va_arg(*lst, int);
			if (ft_check_conv_spe(s[++p_->index]))
				st_->conv_spe = s[p_->index++];
			return (1);
		}
		if (ft_get_p2(s, p_, st_, j) == -1)
			return (-1);
	}
	if (ft_check_conv_spe(s[p_->index]))
	{
		st_->conv_spe = s[p_->index];
		p_->index += 1;
	}
	return (1);
}
