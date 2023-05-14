/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tminta <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:48:46 by tminta            #+#    #+#             */
/*   Updated: 2022/07/07 15:48:52 by tminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
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
