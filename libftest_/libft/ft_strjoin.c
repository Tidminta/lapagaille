/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 21:03:18 by tidminta          #+#    #+#             */
/*   Updated: 2019/12/18 22:12:19 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*alloc;

	alloc = NULL;
	len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	if (!(alloc = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	ft_bzero(alloc, len);
	alloc = ft_strdup(s1);
	ft_strlcat(alloc, s2, (len));
	return (alloc);
}
