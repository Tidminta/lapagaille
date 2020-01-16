/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:47:08 by tidminta          #+#    #+#             */
/*   Updated: 2020/01/14 22:15:00 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*alloc;
	size_t	len;

	len = ft_strlen(s1) + 1;
	if (s1[0] == 0)
	{
		if (!(alloc = ft_calloc(1, sizeof(char))))
			return (NULL);
		return (alloc);
	}
	if (!(alloc = ft_calloc(len, sizeof(char))))
		return (NULL);
	ft_strlcpy(alloc, s1, len);
	return (alloc);
}
