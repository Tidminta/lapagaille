/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 17:22:19 by tidminta          #+#    #+#             */
/*   Updated: 2020/04/20 20:08:00 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_char(t_infos_ *st_, t_params_ *p)
{
	size_t	len;

	len = (size_t)st_->width;
	if (st_->flag_moins)
	{
		st_->flag_zero = 0;
		st_->flag_diez = 0;
	}
	if ((!st_->precis && !st_->flag_zero) && !st_->flag_moins)
	{
		while (len-- > 1)
			ft_putchar_fd2(' ', 1, p);
		ft_putchar_fd2(st_->arg_char, 1, p);
	}
	else if ((!st_->precis && !st_->flag_zero) && st_->flag_moins)
	{
		ft_putchar_fd2(st_->arg_char, 1, p);
		while (len-- > 1)
			ft_putchar_fd2(' ', 1, p);
	}
}
