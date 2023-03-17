/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tminta <tminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:41:32 by motoure           #+#    #+#             */
/*   Updated: 2023/03/16 19:00:40 by tminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*return_value;

	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
	{
		if (!(return_value = malloc(sizeof(char) * 1)))
			return (0);
		if (!(return_value[0] == '\0'))
			return_value[0] = '\0';
		return (return_value);
	}
	if (!(return_value = malloc(sizeof(char) * len + 1)))
		return (0);
	ft_memcpy(return_value, s + start, len);
	return_value[len] = '\0';
	return (return_value);
}
