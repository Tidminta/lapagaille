/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin_0flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 19:43:30 by tidminta          #+#    #+#             */
/*   Updated: 2020/04/20 20:21:00 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_flag0_wp(t_infos_ *st_, t_params_ *p, size_t len)
{
	size_t len2;

	if ((size_t)st_->precis > len)
	{
		len2 = (st_->arg_bin >= 0) ? st_->width : (st_->width - 1);
		while (len2-- > (size_t)st_->precis)
			ft_putchar_fd2(' ', 1, p);
	}
	else
	{
		len2 = len;
		while (len2++ < (size_t)st_->width)
			ft_putchar_fd2(' ', 1, p);
	}
	while (len++ < (size_t)st_->precis)
		ft_putchar_fd2('0', 1, p);
	ft_putnbr_base(st_->arg_bin, "01", p);
}

static void		ft_flag0_w(t_infos_ *st_, t_params_ *p, size_t len)
{
	while (len++ < (size_t)st_->width)
		ft_putchar_fd2(' ', 1, p);
	if (!st_->arg_bin && st_->is_precis)
		ft_putchar_fd2(' ', 1, p);
	else
		ft_putnbr_base(st_->arg_bin, "01", p);
}

void			ft_bin_0flag(t_infos_ *st_, t_params_ *p, size_t len)
{
	if (!st_->flag_moins && !st_->flag_zero)
		ft_flag0_wp(st_, p, len);
	else if (st_->width && !(st_->precis))
		ft_flag0_w(st_, p, len);
	else if (!(st_->width) && st_->precis)
	{
		while (len++ < (size_t)st_->precis)
			ft_putchar_fd2('0', 1, p);
		ft_putnbr_base(st_->arg_bin, "01", p);
	}
	else
	{
		if (!st_->arg_bin && (st_->is_precis && !st_->precis))
			;
		else
			ft_putnbr_base(st_->arg_bin, "01", p);
	}
}
