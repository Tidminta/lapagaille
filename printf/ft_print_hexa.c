/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 19:55:20 by tidminta          #+#    #+#             */
/*   Updated: 2020/04/18 16:52:39 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_printf_hexa(t_infos_ *st_, t_params_ *p)
{
	size_t	len;
	size_t	tmp;

	st_->flag_zero = (st_->flag_moins) ? 0 : st_->flag_zero;
	tmp = st_->arg_hexa;
	len = 1;
	while (tmp && ((tmp / 16) > 0))
	{
		tmp = tmp / 16;
		len++;
	}
	if (!st_->flag_moins && !st_->flag_zero)
		ft_hexa_0_flags(st_, p, len);
	else if ((st_->flag_zero && !st_->flag_moins))
		ft_hexa_flag_0(st_, p, len);
	else if (st_->flag_moins && !st_->flag_zero)
		ft_hexa_flagminus(st_, p, len);
}
