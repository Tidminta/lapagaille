/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 21:55:49 by tidminta          #+#    #+#             */
/*   Updated: 2019/12/14 22:13:59 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	i = -1;
	j = 0;
	if (needle[0] == '\0')
		return (haystack);
	while ((haystack[++i] && needle[j]) && (i < len))
	{
		if ((haystack[i] && needle[j]) && (haystack[i] == needle[j]))
		{
			k = i;
			while ((haystack[i] && needle[j]) && (haystack[i] == needle[j]))
			{
				if (needle[j + 1] == '\0')
					return (&haystack[k]);
				i++;
				j++;
			}
			i = k;
		}
		j = 0;
	}
	return (0);
}
