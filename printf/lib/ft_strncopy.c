/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncopy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:25:47 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/28 14:31:23 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t          ft_strncopy(char *dst, const char *src, int *start, size_t dstsize)
{
        size_t  i;
        size_t  j;

        i = 0;
        j = 0;
        if (!src || !dst)
                return (0);
        if (dstsize == 0)
                return (i);
        while (src[*i] && j < dstsize - 1)
        {
                dst[j] = src[*i];
                j++;
				*i += 1;
        }
        dst[j] = '\0';
        return (1);
}
