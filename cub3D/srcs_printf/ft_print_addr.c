/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 20:22:39 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/04 18:56:39 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_printf_addr(t_infos_ *st_, t_params_ *p)
{
	size_t	len;
	size_t	tmp;

	len = 1;
	tmp = st_->arg_addr;
	while (tmp && ((tmp / 16) > 0))
	{
		tmp = tmp / 16;
		len++;
	}
	if (!st_->flag_zero && !st_->flag_diez && !st_->flag_moins)
		ft_addr_0flag(st_, p, len);
	else if (!(st_->flag_zero && st_->flag_diez) && (st_->flag_moins))
		ft_addr_flagminus(st_, p, len);
}
