/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:22:57 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/04 18:37:34 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	i = 0;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (i < n)
	{
		dest[i] = source[i];
		if (dest[i] == (unsigned char)c)
			return (dest + 1 + i);
		i++;
	}
	return (NULL);
}
