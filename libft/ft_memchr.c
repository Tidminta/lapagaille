/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:06:14 by tidminta          #+#    #+#             */
/*   Updated: 2019/12/02 23:15:01 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	void			*tmp;
	unsigned char	match;

	i = 0;
	match = (unsigned char)c;
	tmp = (void *)s;
	while (i < n)
	{
		if (((unsigned char *)tmp)[i] == match)
		{
			return (&tmp[i]);
		}
		i++;
	}
	return (NULL);
}
