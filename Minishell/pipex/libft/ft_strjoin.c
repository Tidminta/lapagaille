/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tminta <tminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:16:41 by motoure           #+#    #+#             */
/*   Updated: 2023/03/16 18:58:44 by tminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

char	*cpy_from_index(int index, const char *src, char *dst)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[index] = src[i];
		index++;
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*return_value;
	int		t_len;

	if (!s1 || !s2)
		return (0);
	t_len = ft_strlen(s1) + ft_strlen(s2);
	if (!(return_value = malloc(sizeof(char) * t_len + 1)))
		return (0);
	cpy_from_index(0, s1, return_value);
	cpy_from_index(ft_strlen(s1), s2, return_value);
	return_value[t_len] = '\0';
	return (return_value);
}