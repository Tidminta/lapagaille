/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 20:39:21 by tidminta          #+#    #+#             */
/*   Updated: 2020/04/01 16:20:54 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


/*
** A SUREMENT SUPP
*/


char			*ft_itoa_base(unsigned int n)
{
    int             i;
    unsigned int    tmp;
    size_t          len;
    char            *alloc;

    tmp = (n > 0) ? n : -n;
    len = (n > 0) ? 1 : 2;
    i = 0;
    while (tmp && ((tmp/10) > 0))
    {
        tmp = tmp/16;
        len++;
    }
    alloc = (char *)malloc(sizeof(char) * len + 1);
    ft_bzero(alloc, len + 1);
    tmp = n;
    if (n < 0)
        alloc[0] = '-';
    while ((--len) && tmp && ((tmp/10) > 0))
    {
        alloc[len] = (tmp % 16) + 48;
        tmp /= 16;
    }
    alloc[len] = (tmp % 16) + 48;
    return (alloc);
}