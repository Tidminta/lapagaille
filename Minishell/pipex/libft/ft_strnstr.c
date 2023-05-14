/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tminta <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:55:21 by tminta            #+#    #+#             */
/*   Updated: 2022/07/07 15:55:27 by tminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;
	char	*src;
	char	*to_find;

	i = 0;
	src = (char *)haystack;
	if (!needle[0])
		return (src);
	to_find = (char *)needle;
	while (src[i] != '\0' && i < len)
	{
		j = 0;
		while (to_find[j] == src[i + j] && (i + j) < len)
		{
			if (to_find[j + 1] == '\0')
			{
				return (src + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
