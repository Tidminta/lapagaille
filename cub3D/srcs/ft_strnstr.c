/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 21:55:49 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/04 18:39:11 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
