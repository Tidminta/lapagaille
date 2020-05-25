/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_flagm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 18:00:21 by tidminta          #+#    #+#             */
/*   Updated: 2020/04/09 18:32:27 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_unsigned_w_hundle(t_infos_ *st_, t_params_ *p, size_t len)
{
	size_t len2;

	if (st_->width && !st_->precis)
	{
		if (!st_->arg_uint && (st_->is_precis && !st_->precis))
			len -= 1;
		while ((len++ < (size_t)st_->width))
			ft_putchar_fd(' ', 1, p);
	}
	else if (st_->width && st_->precis)
	{
		len2 = st_->width;
		if ((st_->width) && (st_->is_precis) && (size_t)st_->precis >= len)
		{
			while (len2-- > (size_t)st_->precis)
				ft_putchar_fd(' ', 1, p);
		}
		else if ((st_->width) && (st_->is_precis) && (size_t)st_->precis < len)
		{
			while (len++ < (size_t)st_->width)
				ft_putchar_fd(' ', 1, p);
		}
	}
}

void			ft_unsigned_flagm(t_infos_ *st_, t_params_ *p, size_t len)
{
	size_t	len2;

	len2 = len;
	if (((st_->width && st_->precis) || (!st_->width && st_->precis)))
		while (len++ < (size_t)st_->precis)
			ft_putchar_fd('0', 1, p);
	if (!st_->arg_uint && (st_->is_precis && !st_->precis))
		;
	else
		ft_putnbr_base(st_->arg_uint, "0123456789", p);
	if (st_->width)
		ft_unsigned_w_hundle(st_, p, len2);
}
