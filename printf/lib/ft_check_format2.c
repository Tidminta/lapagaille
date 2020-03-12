/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 21:23:00 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/29 22:21:22 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_infos_	*ft_init_struct(void)
{
	t_infos_ *ptr;

	ptr = (t_infos_ *)malloc(sizeof(t_infos_));
	ptr->flag_zero = 0;
	ptr->flag_moins = 0;
	ptr->width = 0;
	ptr->precis = 0;
	ptr->conv_len = 0;
	return (ptr);
}
