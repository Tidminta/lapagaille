/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:25:42 by tidminta          #+#    #+#             */
/*   Updated: 2020/01/13 17:06:43 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*alloc;
	size_t	i;

	i = -1;
	alloc = NULL;
	if (!(alloc = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_bzero(alloc, (len + 1));
	while ((++i < len) && (s[start]))
	{
		alloc[i] = s[start];
		start++;
	}
	return (alloc);
}
