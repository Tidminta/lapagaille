/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:30:28 by tidminta          #+#    #+#             */
/*   Updated: 2020/04/18 16:46:02 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_printf_digits(t_infos_ *st_, t_params_ *p)
{
	size_t	len;
	size_t	tmp;

	st_->flag_zero = (st_->flag_moins) ? 0 : st_->flag_zero;
	tmp = st_->arg_int;
	len = (st_->arg_int >= 0) ? 1 : 2;
	tmp = (st_->arg_int < 0) ? -st_->arg_int : st_->arg_int;
	while (tmp && (tmp / 10) > 0)
	{
		tmp /= 10;
		len++;
	}
	if (!st_->flag_moins && !st_->flag_zero)
		ft_d_0flag(st_, p, len);
	else if ((st_->flag_zero && !st_->flag_moins))
		ft_d_flag0(st_, p, len);
	else if (st_->flag_moins && !st_->flag_zero)
		ft_d_flagminus(st_, p, len);
}
