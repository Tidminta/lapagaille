/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addr_flagminus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 21:04:59 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/04 18:53:59 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void			ft_flagm_wp(t_infos_ *st_, t_params_ *p, size_t len)
{
	size_t	width_len;
	size_t	precis_len;

	width_len = st_->width;
	precis_len = ((size_t)st_->precis < len) ? len + 2 : st_->precis + 2;
	ft_putstr_fd2("0x", 1, p);
	while (len++ < (size_t)st_->precis)
		ft_putchar_fd2('0', 1, p);
	if (st_->precis != 0)
		ft_putnbr_base(st_->arg_addr, "0123456789abcdef", p);
	while (width_len-- > precis_len)
		ft_putchar_fd2(' ', 1, p);
}

static void			ft_flagm_only_w(t_infos_ *st_, t_params_ *p, size_t len)
{
	len = (st_->arg_addr == 0 && st_->is_precis) ? 2 : len + 2;
	ft_putstr_fd2("0x", 1, p);
	if (st_->arg_addr == 0 && !st_->is_precis)
		ft_putnbr_base(st_->arg_addr, "0123456789abcdef", p);
	else if (st_->arg_addr != 0)
		ft_putnbr_base(st_->arg_addr, "0123456789abcdef", p);
	while (len++ < (size_t)st_->width)
		ft_putchar_fd2(' ', 1, p);
}

static void			ft_flagm_only_p(t_infos_ *st_, t_params_ *p, size_t len)
{
	ft_putstr_fd2("0x", 1, p);
	while (len++ < (size_t)st_->precis)
		ft_putchar_fd2('0', 1, p);
	if (st_->precis != 0)
		ft_putnbr_base(st_->arg_addr, "0123456789abcdef", p);
}

void				ft_addr_flagminus(t_infos_ *st_, t_params_ *p, size_t len)
{
	if (st_->width && st_->precis)
		ft_flagm_wp(st_, p, len);
	else if (st_->width && !st_->precis)
		ft_flagm_only_w(st_, p, len);
	else if (!st_->width && st_->precis)
		ft_flagm_only_p(st_, p, len);
	else
	{
		ft_putstr_fd2("0x", 1, p);
		if ((st_->arg_addr == 0 && st_->is_precis == 1))
			;
		else
			ft_putnbr_base(st_->arg_addr, "0123456789abcdef", p);
	}
}
