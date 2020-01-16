/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:17:52 by tidminta          #+#    #+#             */
/*   Updated: 2020/01/15 01:16:24 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*alloc;
	size_t			len;
	unsigned int	i;

	alloc = NULL;
	if (!s || !(*f))
		return (NULL);
	len = ft_strlen(s) + 1;
	i = 0;
	if (!(alloc = ft_calloc(len, sizeof(char))))
		return (NULL);
	while (s[i])
	{
		alloc[i] = (*f)(i, s[i]);
		i++;
	}
	return (alloc);
}
