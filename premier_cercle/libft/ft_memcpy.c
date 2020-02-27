/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:46:13 by tidminta          #+#    #+#             */
/*   Updated: 2020/01/14 02:40:41 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst_tmp;
	unsigned char		*src_tmp;
	unsigned char		*tmp;

	tmp = (unsigned char *)dst;
	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	i = 0;
	if (dst == src)
		return (dst);
	while (i < n)
	{
		dst_tmp[i] = src_tmp[i];
		i++;
	}
	return (tmp);
}
