/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pourcent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 15:28:48 by tidminta          #+#    #+#             */
/*   Updated: 2020/04/11 19:20:54 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_pourcent(t_infos_ *st_, t_params_ *p)
{
	size_t	len;

	len = (size_t)st_->width;
	st_->flag_zero = (st_->flag_moins) ? 0 : st_->flag_zero;
	if (!st_->flag_moins)
	{
		if (st_->flag_zero)
		{
			while (len-- > 1)
				ft_putchar_fd('0', 1, p);
			ft_putchar_fd(st_->arg_char, 1, p);
		}
		else
		{
			while (len-- > 1)
				ft_putchar_fd(' ', 1, p);
			ft_putchar_fd(st_->arg_char, 1, p);
		}
	}
	else if (st_->flag_moins)
	{
		ft_putchar_fd(st_->arg_char, 1, p);
		while (len-- > 1)
			ft_putchar_fd(' ', 1, p);
	}
}
