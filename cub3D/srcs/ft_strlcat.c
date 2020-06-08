/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:49:56 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/04 18:38:56 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int i;
	unsigned int y;
	unsigned int len;
	unsigned int tlen;

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
