/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_flag0.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 14:47:37 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/04 18:57:34 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void		ft_unsigned_width_h(t_infos_ *st_, t_params_ *p, size_t len)
{
	size_t len2;

	if ((st_->width) && (st_->is_precis) && (size_t)st_->precis >= len)
	{
		len2 = st_->width;
		while (len2-- > (size_t)st_->precis)
			ft_putchar_fd2(' ', 1, p);
	}
	else if ((st_->width) && (st_->is_precis) && (size_t)st_->precis < len)
	{
		len = (st_->arg_uint) ? len : 0;
		while (len++ < (size_t)st_->width)
			ft_putchar_fd2(' ', 1, p);
	}
	else if (st_->width && !st_->precis && st_->is_precis)
	{
		len2 = (st_->arg_uint) ? len : 0;
		while (len2++ < (size_t)st_->width)
			ft_putchar_fd2(' ', 1, p);
	}
}

static void		ft_unsigned_precis_h(t_infos_ *st_, t_params_ *p, size_t len)
{
	if (((st_->width && st_->precis) || (!st_->width && st_->precis)))
		while (len++ < (size_t)st_->precis)
			ft_putchar_fd2('0', 1, p);
	else if ((st_->width) && !st_->is_precis)
		while ((len++ < (size_t)st_->width))
			ft_putchar_fd2('0', 1, p);
}

void			ft_unsigned_flag0(t_infos_ *st_, t_params_ *p, size_t len)
{
	if (st_->width)
		ft_unsigned_width_h(st_, p, len);
	ft_unsigned_precis_h(st_, p, len);
	if (!st_->arg_uint && (!st_->width && !st_->precis) && st_->is_precis)
		;
	else if (!st_->arg_uint && st_->is_precis && !st_->precis)
		;
	else
		ft_putnbr_base(st_->arg_uint, "0123456789", p);
}
