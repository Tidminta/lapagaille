/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:22:29 by tidminta          #+#    #+#             */
/*   Updated: 2020/03/16 18:11:06 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*ft_itoa2(unsigned int n)
{
    int             i;
    unsigned int    tmp;
    size_t          len;
    char            *alloc;

    tmp = n;
    len = 1;
    i = 0;
    while (tmp && ((tmp/10) > 0))
    {
        tmp = tmp/10;
        len++;
    }
    alloc = (char *)malloc(sizeof(char) * len + 1);
    ft_bzero(alloc, len + 1);
    tmp = n;
    while ((--len) && tmp && ((tmp/10) > 0))
    {
        alloc[len] = (tmp % 10) + 48;
        tmp /= 10;
    }
    alloc[len] = (tmp % 10) + 48;
    return (alloc);
}