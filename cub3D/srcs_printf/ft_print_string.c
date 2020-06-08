/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 18:05:27 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/04 18:56:56 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_printf_string(t_infos_ *st_, t_params_ *p)
{
	size_t	len;

	len = (st_->arg_str) ? ft_strlen(st_->arg_str) : 6;
	if (!st_->flag_moins)
		ft_string_0flag(st_, p, len);
	else if (st_->flag_moins)
		ft_string_flagm(st_, p, len);
}
