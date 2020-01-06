/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 22:30:24 by tidminta          #+#    #+#             */
/*   Updated: 2019/12/18 22:32:36 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char        *ft_strjoin(char const *s1, char const *s2)
{    char    *alloc;
    int len;

    alloc = NULL;
    len = ft_strlen(s1) + ft_strlen(s2) + 1;
    if (!(alloc = ft_calloc(len, sizeof(char))))
        return (NULL);
    ft_strlcat(alloc,s1,len);
    ft_strlcat(alloc, s2, len);
    return (alloc);
}
