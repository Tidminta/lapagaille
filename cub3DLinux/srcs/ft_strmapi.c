/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:17:52 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/04 18:39:06 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*alloc;
	unsigned int	len;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	if (!(alloc = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s[i] != '\0')
	{
		alloc[i] = f(i, s[i]);
		i++;
	}
	alloc[i] = '\0';
	return (alloc);
}
