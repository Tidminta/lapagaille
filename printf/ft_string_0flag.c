/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_0flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 20:31:28 by tidminta          #+#    #+#             */
/*   Updated: 2020/04/20 20:34:28 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_str_w(t_infos_ *st_, t_params_ *p, size_t len, size_t *indic)
{
	size_t i;

	i = -1;
	if (!st_->precis && st_->is_precis == 1)
	{
		while (++i < (size_t)st_->width)
			ft_putchar_fd2(' ', 1, p);
		*indic = 1;
	}
	else if (!st_->precis)
		while (len++ < (size_t)st_->width)
			ft_putchar_fd2(' ', 1, p);
	else
	{
		if ((len < (size_t)st_->precis))
			while (len++ < (size_t)st_->width)
				ft_putchar_fd2(' ', 1, p);
		else
		{
			len = (size_t)st_->precis;
			while (len++ < (size_t)st_->width)
				ft_putchar_fd2(' ', 1, p);
		}
	}
}

void			ft_string_0flag(t_infos_ *st_, t_params_ *p, size_t len)
{
	size_t	indic;
	size_t	i;

	indic = 0;
	i = -1;
	if (st_->width)
		ft_str_w(st_, p, len, &indic);
	if (st_->precis)
	{
		if (len > (size_t)st_->precis)
		{
			if (!st_->arg_str)
				ft_putstr_fd2(st_->arg_str, 1, p);
			else
				while (++i < (size_t)st_->precis)
					ft_putchar_fd2(st_->arg_str[i], 1, p);
		}
		else
			ft_putstr_fd2(st_->arg_str, 1, p);
	}
	else
	{
		if (indic == 0 && !st_->is_precis)
			ft_putstr_fd2(st_->arg_str, 1, p);
	}
}
