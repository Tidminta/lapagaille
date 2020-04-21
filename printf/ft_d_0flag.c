/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_0flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 15:52:00 by tidminta          #+#    #+#             */
/*   Updated: 2020/04/20 20:37:11 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_d_width_precis(t_infos_ *st_, t_params_ *p, size_t len)
{
	size_t	len2;

	if ((size_t)st_->precis >= len)
	{
		len2 = (st_->arg_int >= 0) ? st_->width : (st_->width - 1);
		while (len2-- > (size_t)st_->precis)
			ft_putchar_fd2(' ', 1, p);
	}
	else
	{
		len2 = len;
		while (len2++ < (size_t)st_->width)
			ft_putchar_fd2(' ', 1, p);
	}
	if (st_->arg_int < 0)
		ft_putchar_fd2('-', 1, p);
	len = (st_->arg_int >= 0) ? len : (len - 1);
	while (len++ < (size_t)st_->precis)
		ft_putchar_fd2('0', 1, p);
	ft_putnbr_fd2(st_->arg_int, 1, p);
}

static void	ft_d_only_width(t_infos_ *st_, t_params_ *p, size_t len)
{
	len = (!st_->arg_int && !st_->precis && st_->is_precis) ? len - 1 : len;
	while (len++ < (size_t)st_->width)
		ft_putchar_fd2(' ', 1, p);
	if (!st_->arg_int && (!st_->precis && st_->is_precis))
		;
	else
	{
		if (st_->arg_int < 0)
			ft_putchar_fd2('-', 1, p);
		ft_putnbr_fd2(st_->arg_int, 1, p);
	}
}

static void	ft_d_only_precis(t_infos_ *st_, t_params_ *p, size_t len)
{
	len = (st_->arg_int >= 0) ? len : (len - 1);
	if (st_->arg_int < 0)
		ft_putchar_fd2('-', 1, p);
	while (len++ < (size_t)st_->precis)
		ft_putchar_fd2('0', 1, p);
	ft_putnbr_fd2(st_->arg_int, 1, p);
}

void		ft_d_0flag(t_infos_ *st_, t_params_ *p, size_t len)
{
	if (st_->width && st_->precis)
		ft_d_width_precis(st_, p, len);
	else if (st_->width && !(st_->precis))
		ft_d_only_width(st_, p, len);
	else if (!(st_->width) && st_->precis)
		ft_d_only_precis(st_, p, len);
	else
	{
		if (!st_->arg_int && (!st_->precis && st_->is_precis))
			;
		else
		{
			if (st_->arg_int < 0)
				ft_putchar_fd2('-', 1, p);
			ft_putnbr_fd2(st_->arg_int, 1, p);
		}
	}
}
