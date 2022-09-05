/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_flagm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 18:11:02 by tidminta          #+#    #+#             */
/*   Updated: 2020/04/20 20:34:42 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_str_p_(t_infos_ *st_, t_params_ *p, size_t len, size_t *i)
{
	if ((st_->precis) && len > (size_t)st_->precis)
	{
		while (*i < (size_t)st_->precis)
		{
			ft_putchar_fd2(st_->arg_str[*i], 1, p);
			*i += 1;
		}
	}
	else
	{
		if (len <= (size_t)st_->precis)
		{
			ft_putstr_fd2(st_->arg_str, 1, p);
			*i += len;
		}
	}
}

void	ft_string_flagm(t_infos_ *st_, t_params_ *p, size_t len)
{
	size_t	i;

	i = 0;
	if (st_->precis || (!st_->precis && st_->is_precis == 1))
		ft_str_p_(st_, p, len, &i);
	else if (!st_->precis && !st_->is_precis)
	{
		ft_putstr_fd2(st_->arg_str, 1, p);
		i += len;
	}
	else if (!st_->precis && !st_->is_precis)
	{
		ft_putstr_fd2(st_->arg_str, 1, p);
		i += len;
	}
	if (st_->width)
	{
		while ((i < ((size_t)st_->width)))
		{
			ft_putchar_fd2(' ', 1, p);
			i++;
		}
	}
}
