/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:54:08 by tidminta          #+#    #+#             */
/*   Updated: 2019/11/26 16:34:47 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	match;

	i = 0;
	match = (char)c;
	while (*s && (*s != match))
		s++;
	if (*s == match)
		return ((char *)s);
	return (NULL);
}
