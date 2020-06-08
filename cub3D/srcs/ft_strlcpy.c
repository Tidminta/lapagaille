/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 18:40:29 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/04 18:38:59 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!src || !dst)
		return (0);
	while (src[i])
		i++;
	if (dstsize == 0)
		return (i);
	while (src[j] && j < dstsize - 1)
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}
