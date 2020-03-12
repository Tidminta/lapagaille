/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:40:02 by tidminta          #+#    #+#             */
/*   Updated: 2020/03/06 17:24:51 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	ft_convert_char(int char_)
{
	printf("[debut ft_convert_char]\n");
	if (ft_isprint(char_))
		return ((char)char_);
	return (0);
}
