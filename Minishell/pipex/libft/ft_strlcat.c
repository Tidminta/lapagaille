/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tminta <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:53:55 by tminta            #+#    #+#             */
/*   Updated: 2022/07/07 15:54:02 by tminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	y;
	unsigned int	len;
	unsigned int	tlen;

	i = 0;
	y = 0;
	len = 0;
	tlen = 0;
	while (dst[i] && i < dstsize)
		i++;
	len = i;
	while (src[y])
		y++;
	tlen = i + y;
	y = 0;
	while (src[y] && (len + y) < dstsize - 1 && dstsize != 0)
	{
		dst[i] = src[y];
		i++;
		y++;
	}
	if (!(i == dstsize))
		dst[i] = '\0';
	return (tlen);
}
