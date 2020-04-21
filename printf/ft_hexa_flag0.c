/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_flag0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 19:28:38 by tidminta          #+#    #+#             */
/*   Updated: 2020/04/20 20:18:38 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_flag0_w(t_infos_ *st_, t_params_ *p, size_t l1, size_t l2)
{
	size_t	res_width;

	if (st_->width && st_->precis)
	{
		if ((size_t)st_->precis >= l1)
		{
			res_width = (st_->width > 1) ? st_->width - 2 : 0;
			l2 = (st_->flag_diez && st_->arg_hexa) ? res_width : st_->width;
			while (l2-- > (size_t)st_->precis)
				ft_putchar_fd2(' ', 1, p);
		}
		else if ((size_t)st_->precis < l1)
		{
			l2 = (st_->flag_diez && st_->arg_hexa) ? (l1 + 2) : l1;
			while (l2++ < (size_t)st_->width)
				ft_putchar_fd2(' ', 1, p);
		}
	}
	else if (((st_->width && !st_->precis) && st_->is_precis))
	{
		l1 = (st_->arg_hexa) ? l1 : 0;
		l2 = (st_->flag_diez && st_->arg_hexa) ? (l1 + 2) : l1;
		while (l2++ < (size_t)st_->width)
			ft_putchar_fd2(' ', 1, p);
	}
}

static	void	ft_flag0_p(t_infos_ *st_, t_params_ *p, size_t len)
{
	if (((st_->width && st_->precis) || (!st_->width && st_->precis)))
	{
		while (len < (size_t)st_->precis)
		{
			ft_putchar_fd2('0', 1, p);
			len++;
		}
	}
	else if ((st_->width) && !st_->is_precis)
	{
		len = (st_->flag_diez && st_->arg_hexa) ? (len + 2) : len;
		while ((len < (size_t)st_->width))
		{
			ft_putchar_fd2('0', 1, p);
			len++;
		}
	}
}

void			ft_hexa_flag_0(t_infos_ *st_, t_params_ *p, size_t len)
{
	size_t len2;

	len2 = 0;
	if (st_->width)
		ft_flag0_w(st_, p, len, len2);
	if (st_->flag_diez && st_->arg_hexa)
		p->conv_len += ft_printf("0%c", st_->conv_spe);
	ft_flag0_p(st_, p, len);
	if (!st_->arg_hexa && !st_->precis && st_->is_precis)
		;
	else
	{
		if (st_->conv_spe == 'x')
			ft_putnbr_base(st_->arg_hexa, "0123456789abcdef", p);
		else
			ft_putnbr_base(st_->arg_hexa, "0123456789ABCDEF", p);
	}
}
