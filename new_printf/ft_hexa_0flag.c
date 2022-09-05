/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_0flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 16:52:27 by tidminta          #+#    #+#             */
/*   Updated: 2020/04/20 20:18:13 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_w_p(t_infos_ *st_, t_params_ *p, size_t len, size_t len2)
{
	size_t res;

	if ((size_t)st_->precis > len)
	{
		if (st_->width > 1)
			res = st_->width - 2;
		else
			res = 0;
		if (st_->flag_diez)
			len2 =  res;
		else
			len2 = st_->width;
		if (st_->flag_diez && !st_->arg_hexa)
			len2 = st_->width;
		else
			len2 = len2;
		while (len2-- > (size_t)st_->precis)
			ft_putchar_fd2(' ', 1, p);
	}
	else
	{
		if (st_->arg_hexa)
			res = len + 2;
		else
			res = len;
		if (st_->flag_diez)
			len2 = res;
		else
			len2 = len;
		while (len2++ < (size_t)st_->width)
			ft_putchar_fd2(' ', 1, p);
	}
	if (st_->flag_diez && st_->arg_hexa)
		p->conv_len += ft_printf("0%c", st_->conv_spe);
	while (len++ < (size_t)st_->precis)
		ft_putchar_fd2('0', 1, p);
	if (st_->conv_spe == 'x')
		ft_putnbr_base(st_->arg_hexa, "0123456789abcdef", p);
	else
		ft_putnbr_base(st_->arg_hexa, "0123456789ABCDEF", p);
}

static void	ft_hexa_only_width(t_infos_ *st_, t_params_ *p, size_t len)
{
	size_t len2;
	size_t res;

	if (st_->arg_hexa)
		res = len + 2;
	else
		res = len;
	if (st_->flag_diez)
		len2 =  res;
	else
		len2 = len;
	while (len2 < (size_t)st_->width)
	{
		ft_putchar_fd2(' ', 1, p);
		len2++;
	}
	if (!st_->arg_hexa && st_->is_precis)
		ft_putchar_fd2(' ', 1, p);
	else
	{
		if (st_->flag_diez && st_->arg_hexa)
		{
			ft_putchar_fd2('0', 1, p);
			ft_putchar_fd2(st_->conv_spe, 1, p);
		}
		if (st_->conv_spe == 'x')
			ft_putnbr_base(st_->arg_hexa, "0123456789abcdef", p);
		else
			ft_putnbr_base(st_->arg_hexa, "0123456789ABCDEF", p);
	}
}

static void	ft_hexa_only_precis(t_infos_ *st_, t_params_ *p, size_t len)
{
	if (st_->flag_diez && st_->arg_hexa)
	{
		ft_putchar_fd2('0', 1, p);
		ft_putchar_fd2(st_->conv_spe, 1, p);
	}
	while (len < (size_t)st_->precis)
	{
		ft_putchar_fd2('0', 1, p);
		len++;
	}
	if (st_->conv_spe == 'x')
		ft_putnbr_base(st_->arg_hexa, "0123456789abcdef", p);
	else
		ft_putnbr_base(st_->arg_hexa, "0123456789ABCDEF", p);
}

static void	ft_hexa_without_params(t_infos_ *st_, t_params_ *p)
{
	if (!st_->arg_hexa && st_->is_precis)
		;
	else
	{
		if (st_->flag_diez && st_->arg_hexa)
		{
			ft_putchar_fd2('0', 1, p);
			ft_putchar_fd2(st_->conv_spe, 1, p);
		}
		if (st_->conv_spe == 'x')
			ft_putnbr_base(st_->arg_hexa, "0123456789abcdef", p);
		else
			ft_putnbr_base(st_->arg_hexa, "0123456789ABCDEF", p);
	}
}

void	ft_hexa_0_flags(t_infos_ *st_, t_params_ *p, size_t len)
{
	size_t len2;

	len2 = 0;
	if (st_->width && st_->precis)
		ft_w_p(st_, p, len, len2);
	else if (st_->width && !(st_->precis))
		ft_hexa_only_width(st_, p, len);
	else if (!(st_->width) && st_->precis)
		ft_hexa_only_precis(st_, p, len);
	else
		ft_hexa_without_params(st_, p);
}
