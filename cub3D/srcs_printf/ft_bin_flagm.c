/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin_flagm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 19:53:18 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/04 18:54:25 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void		ft_bin_width_hundle(t_infos_ *st_, t_params_ *p, size_t len)
{
	if (st_->width && !st_->precis)
	{
		if (!st_->arg_bin && (st_->is_precis && !st_->precis))
			len -= 1;
		while ((len++ < (size_t)st_->width))
			ft_putchar_fd2(' ', 1, p);
	}
	else if (st_->width && st_->precis)
	{
		if ((st_->width) && (st_->is_precis) && (size_t)st_->precis >= len)
		{
			len = st_->width;
			while (len-- > (size_t)st_->precis)
				ft_putchar_fd2(' ', 1, p);
		}
		else if ((st_->width) && (st_->is_precis) && (size_t)st_->precis < len)
		{
			while (len++ < (size_t)st_->width)
				ft_putchar_fd2(' ', 1, p);
		}
	}
}

void			ft_bin_flagm(t_infos_ *st_, t_params_ *p, size_t len)
{
	if (((st_->width && st_->precis) || (!st_->width && st_->precis)))
		while (len++ < (size_t)st_->precis)
			ft_putchar_fd2('0', 1, p);
	if (!st_->arg_bin && (st_->is_precis && !st_->precis))
		;
	else
		ft_putnbr_base(st_->arg_bin, "01", p);
	ft_bin_width_hundle(st_, p, len);
}
