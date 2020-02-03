/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 18:40:29 by tidminta          #+#    #+#             */
/*   Updated: 2020/01/15 01:43:51 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize >= 0 && src && dst)
	{
		while (src[i] && dstsize > 1)
		{
			dst[i] = src[i];
			i++;
			dstsize--;
		}
		if (dstsize > 0)
		{
			dst[i] = '\0';
		}
		return (ft_strlen(src));
	}
	return (0);
}
