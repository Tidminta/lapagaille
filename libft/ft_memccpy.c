/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:22:57 by tidminta          #+#    #+#             */
/*   Updated: 2019/11/14 17:54:16 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	new_c;
	size_t			i;

	new_c = (unsigned char)c;
	i = 0;
	if (n > 0)
	{
		while ((i < n) && (((unsigned char *)src)[i - 1] != new_c))
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
		if (((unsigned char *)src)[i - 1] == new_c)
		{
			return (dst + i);
		}
	}
	return (NULL);
}
