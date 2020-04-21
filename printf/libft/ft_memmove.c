/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:37:34 by tidminta          #+#    #+#             */
/*   Updated: 2020/01/16 04:26:20 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*src_tmp;
	unsigned char	*dst_tmp;

	src_tmp = (unsigned char *)src;
	dst_tmp = (unsigned char *)dst;
	i = 0;
	if (src == dst)
		return (dst);
	if (dst_tmp > src_tmp)
	{
		while (++i <= len)
			dst_tmp[len - i] = src_tmp[len - i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dst_tmp[i] = src_tmp[i];
			i++;
		}
	}
	return (dst);
}
