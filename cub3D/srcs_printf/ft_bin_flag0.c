/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin_flag0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 19:36:10 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/04 18:54:18 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void		ft_bin_width_hundle(t_infos_ *st_, t_params_ *p, size_t len)
{
	size_t	len2;

	len2 = st_->width;
	if (st_->width && st_->precis)
	{
		if ((st_->width) && (st_->is_precis) && (size_t)st_->precis >= len)
			while (len2-- > (size_t)st_->precis)
				ft_putchar_fd2(' ', 1, p);
		else if ((st_->width) && (st_->is_precis) && (size_t)st_->precis < len)
			while (len++ < (size_t)st_->width)
				ft_putchar_fd2(' ', 1, p);
	}
}

static void		ft_bin_precis_hundle(t_infos_ *st_, t_params_ *p, size_t len)
{
	if (((st_->width && st_->precis) || (!st_->width && st_->precis)))
		while (len++ < (size_t)st_->precis)
			ft_putchar_fd2('0', 1, p);
	else if ((st_->width) && !st_->is_precis)
		while ((len++ < (size_t)st_->width))
			ft_putchar_fd2('0', 1, p);
}

void			ft_bin_flag0(t_infos_ *st_, t_params_ *p, size_t len)
{
	ft_bin_width_hundle(st_, p, len);
	ft_bin_precis_hundle(st_, p, len);
	ft_putnbr_base(st_->arg_bin, "01", p);
}
