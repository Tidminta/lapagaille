/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 14:38:38 by tidminta          #+#    #+#             */
/*   Updated: 2020/04/09 18:36:16 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_printf_unsigned(t_infos_ *st_, t_params_ *p)
{
	size_t	first_len;
	size_t	tmp;

	st_->flag_zero = (st_->flag_moins) ? 0 : st_->flag_zero;
	tmp = st_->arg_uint;
	first_len = 1;
	while (tmp && (tmp / 10) > 0)
	{
		tmp /= 10;
		first_len++;
	}
	if (!st_->flag_moins && !st_->flag_zero)
		ft_unsigned_0flag(st_, p, first_len);
	else if ((st_->flag_zero && !st_->flag_moins))
		ft_unsigned_flag0(st_, p, first_len);
	else if (st_->flag_moins && !st_->flag_zero)
		ft_unsigned_flagm(st_, p, first_len);
}
