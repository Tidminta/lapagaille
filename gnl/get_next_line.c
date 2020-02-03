/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:15:23 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/03 21:38:08 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	char *dst;

	dst = s;
	while (n-- > 0)
	{
		*dst = '\0';
		dst++;
	}
	return ;
}

char	*ft_strdup(const char *s1)
{
	char	*alloc;
	size_t	len;

	len = ft_strlen(s1) + 1;
	if (s1[0] == 0)
	{
		if (!(alloc = ft_calloc(1, sizeof(char))))
			return (NULL);
		return (alloc);
	}
	if (!(alloc = ft_calloc(len, sizeof(char))))
		return (NULL);
	ft_strlcpy(alloc, s1, len);
	return (alloc);
}

char	*ft_strchr(const char *s, int c)
{
	while ((*s && *s != (char)c))
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!src || !dst)
		return (0);
	while (src[i])
		i++;
	if (dstsize == 0)
		return (i);
	while (src[j] && j < dstsize - 1)
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}

int		get_next_line(int fd, char **line)
{
	static char			*str;
	char				buff[BUFF_SIZE + 1];
	// char				*tmp;
	static ssize_t		rd;
	size_t				i;

	i = 0;
	buff[BUFF_SIZE] = '\0';
	if (!str)
		str = ft_strdup("");
	while ((!ft_strchr(buff, 10) && (rd = read(fd, buff, BUFF_SIZE)) > 0))
	{
		str = ft_strjoin(str, buff);
	}
	if (!((*line) = ft_strdup(str)))
		return (-1);
	while ((*line)[i] != '\n')
		i++;
	ft_strlcpy((*line), (*line), i + 1);
	if (!(str = ft_strchr(str, 10)))
		return (0);
	str++;
	if (rd != 0)
		return (1);
	return (0);
}
