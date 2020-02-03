/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:15:32 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/03 18:59:33 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < dstsize)
		i++;
	while (src[j] && (i + j + 1) < dstsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i + j < dstsize)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*alloc;
	int		len;

	alloc = NULL;
	if (!s1 || !s2)
		return (ft_strdup(""));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(alloc = ft_calloc(len, sizeof(char))))
		return (NULL);
	ft_strlcat(alloc, s1, len);
	ft_strlcat(alloc, s2, len);
	return (alloc);
}

void		*ft_calloc(size_t count, size_t size)
{
	void	*alloc;

	if (count == 0 || size == 0)
		return (ft_strdup(""));
	if (!(alloc = (char *)malloc(size * count)))
		return (NULL);
	ft_bzero(alloc, count * size);
	return (alloc);
}
