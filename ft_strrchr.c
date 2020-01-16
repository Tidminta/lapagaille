/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:44:04 by tidminta          #+#    #+#             */
/*   Updated: 2020/01/15 01:44:40 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	match;

	i = 0;
	while (s[i])
		i++;
	match = (char)c;
	while (i > 0 && (s[i] != match))
	{
		i--;
	}
	if (s[i] == match)
		return ((char*)s + i);
	return (NULL);
}
