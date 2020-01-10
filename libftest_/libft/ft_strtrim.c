/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 22:16:34 by tidminta          #+#    #+#             */
/*   Updated: 2020/01/09 20:21:39 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_present(const char *charset, char c)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	size_t	len;
	char	*alloc;

	i = -1;
	start = 0;
	len = ft_strlen(s1);
	end = 0;
	while ((s1[++i]) && ft_present(set, s1[i]) == 1)
		start++;
	while ((s1[--len]) && ft_present(set, s1[len]) == 1)
		end++;
	i = ft_strlen(s1) - start;
	if (i == 0)
	{
		if (!(alloc = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		ft_bzero(alloc, 1);
		return (alloc);
	}
	i -= end;
	return (ft_substr(s1, start, i));
}
