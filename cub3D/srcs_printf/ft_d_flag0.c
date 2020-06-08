/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_flag0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 18:03:16 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/04 18:54:36 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void		ft_flag0_width_handle(t_infos_ *st_, t_params_ *p, size_t len)
{
	size_t len2;

	if (st_->width && st_->precis)
	{
		if ((st_->width) && (st_->is_precis) && (size_t)st_->precis >= len)
		{
			len2 = (st_->arg_int >= 0) ? st_->width : (st_->width - 1);
			while (len2-- > (size_t)st_->precis)
				ft_putchar_fd2(' ', 1, p);
		}
		else if ((st_->width) && (st_->is_precis) && (size_t)st_->precis < len)
		{
			len2 = len;
			while (len2++ < (size_t)st_->width)
				ft_putchar_fd2(' ', 1, p);
		}
	}
	else if (st_->width && !st_->precis && st_->is_precis)
	{
		len2 = (st_->arg_int) ? len : 0;
		while (len2++ < (size_t)st_->width)
			ft_putchar_fd2(' ', 1, p);
	}
}

static void		ft_flag0_precis_handle(t_infos_ *st_, t_params_ *p, size_t len)
{
	if (((st_->width && st_->precis) || (!st_->width && st_->precis)))
	{
		len = (st_->arg_int >= 0) ? len : len - 1;
		while (len++ < (size_t)st_->precis)
			ft_putchar_fd2('0', 1, p);
	}
	else if ((st_->width) && !st_->is_precis)
		while ((len++ < (size_t)st_->width))
			ft_putchar_fd2('0', 1, p);
}

void			ft_d_flag0(t_infos_ *st_, t_params_ *p, size_t len)
{
	ft_flag0_width_handle(st_, p, len);
	if (st_->arg_int < 0)
		ft_putchar_fd2('-', 1, p);
	ft_flag0_precis_handle(st_, p, len);
	if (!st_->arg_int && (!st_->width && !st_->precis) && st_->is_precis)
		;
	else
	{
		if (!st_->arg_int && !st_->precis && st_->is_precis)
			;
		else
			ft_putnbr_fd2(st_->arg_int, 1, p);
	}
}
