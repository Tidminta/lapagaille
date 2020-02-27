/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 21:55:49 by tidminta          #+#    #+#             */
/*   Updated: 2020/01/14 20:25:31 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*tmp;

	i = -1;
	j = 0;
	tmp = (char *)haystack;
	if (needle[0] == '\0' || haystack == needle)
		return (tmp);
	while ((haystack[++i] && needle[j]) && (i < len))
	{
		if ((haystack[i] && needle[j]) && (haystack[i] == needle[j]))
		{
			k = i;
			while ((haystack[i++] && needle[j++]) &&
				(haystack[i] == needle[j]) && (i < len))
				if (needle[j + 1] == '\0')
					return (&tmp[k]);
			i = k;
		}
		j = 0;
	}
	return (0);
}
