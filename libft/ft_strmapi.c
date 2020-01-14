/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:17:52 by tidminta          #+#    #+#             */
/*   Updated: 2020/01/14 01:58:07 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*alloc;
	size_t			len;
	unsigned int	i;

	len = ft_strlen(s) + 1;
	i = 0;
	if ((!s) || !(alloc = ft_calloc(len, sizeof(char))))
		return (NULL);
	while (s[i])
	{
		alloc[i] = (*f)(i, s[i]);
		i++;
	}
	return (alloc);
}
