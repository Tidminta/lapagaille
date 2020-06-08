/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bin_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 16:27:51 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/04 18:56:42 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		ft_printf_bin(t_infos_ *st_, t_params_ *p)
{
	size_t	first_len;
	size_t	tmp;

	st_->flag_zero = (st_->flag_moins) ? 0 : st_->flag_zero;
	tmp = st_->arg_bin;
	first_len = 1;
	while (tmp && (tmp / 2) > 0)
	{
		tmp /= 2;
		first_len++;
	}
	if (!st_->flag_moins && !st_->flag_zero)
		ft_bin_0flag(st_, p, first_len);
	else if ((st_->flag_zero && !st_->flag_moins))
		ft_bin_flag0(st_, p, first_len);
	else if (st_->flag_moins && !st_->flag_zero)
		ft_bin_flagm(st_, p, first_len);
}
