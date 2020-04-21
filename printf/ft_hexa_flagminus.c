/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_flagminus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 20:07:43 by tidminta          #+#    #+#             */
/*   Updated: 2020/04/20 20:19:04 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_hexa_flagm_width(t_infos_ *st_, t_params_ *p, size_t l1, int r1)
{
	size_t	l2;

	if (st_->width && !st_->precis)
	{
		l2 = (st_->arg_hexa) ? l1 : 0;
		l2 = (st_->flag_diez && st_->arg_hexa) ? l1 + 2 : l2;
		l2 = (!st_->arg_hexa && !st_->is_precis) ? 1 : l2;
		while ((l2++ < (size_t)st_->width))
			ft_putchar_fd2(' ', 1, p);
	}
	else if (st_->width && st_->precis)
	{
		if ((st_->width) && (st_->is_precis) && (size_t)st_->precis >= l1)
		{
			l2 = (st_->flag_diez && st_->arg_hexa) ? r1 : st_->width;
			while ((size_t)l2-- > (size_t)st_->precis)
				ft_putchar_fd2(' ', 1, p);
		}
		else if ((st_->width) && (st_->is_precis) && (size_t)st_->precis < l1)
		{
			l2 = (st_->flag_diez) ? (l1 + 2) : l1;
			while ((size_t)l2++ < (size_t)st_->width)
				ft_putchar_fd2(' ', 1, p);
		}
	}
}

void		ft_hexa_flagminus(t_infos_ *st_, t_params_ *p, size_t len)
{
	size_t	len2;
	int		res_width;

	len2 = len;
	if (st_->flag_diez && (st_->arg_hexa != 0))
		p->conv_len += ft_printf("0%c", st_->conv_spe);
	if (((st_->width && st_->precis) || (!st_->width && st_->precis)))
		while (len++ < (size_t)st_->precis)
			ft_putchar_fd2('0', 1, p);
	if (!st_->arg_hexa && (st_->is_precis && !st_->precis))
		;
	else
	{
		if (st_->conv_spe == 'x')
			ft_putnbr_base(st_->arg_hexa, "0123456789abcdef", p);
		else
			ft_putnbr_base(st_->arg_hexa, "0123456789ABCDEF", p);
	}
	res_width = (st_->width > 1) ? st_->width - 2 : 0;
	ft_hexa_flagm_width(st_, p, len2, res_width);
}
