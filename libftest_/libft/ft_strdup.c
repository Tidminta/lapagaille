/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:47:08 by tidminta          #+#    #+#             */
/*   Updated: 2019/12/18 20:16:49 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char *alloc;

	if (s1[0] == 0)
	{
		if (!(alloc = ft_calloc(1, sizeof(s1))))
			return (NULL);
		return (alloc);
	}
	if (!(alloc = ft_calloc(ft_strlen(s1), sizeof(s1))))
		return (NULL);
	ft_strlcpy(alloc, s1, (ft_strlen(s1) + 1));
	return (alloc);
}
