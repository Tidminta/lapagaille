/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:15:23 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/14 15:19:33 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*tab;
	int		i;

	if (!s || start < 0)
		return (NULL);
	if (start > ft_strlen(s))
	{
		if (s)
			free(s);
		return (NULL);
	}
	if (!(tab = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (s[start] != '\0' && i < len)
	{
		tab[i] = s[start + i];
		i++;
	}
	tab[i] = '\0';
	free(s);
	return (tab);
}

char		*ft_strdup(char *s1)
{
	char	*alloc;
	int		i;
	int		len;

	i = 0;
	if (!s1 || s1[0] == 0)
	{
		if (!(alloc = (char *)malloc(sizeof(char))))
			return (NULL);
		alloc[0] = '\0';
		return (alloc);
	}
	len = ft_strlen(s1) + 1;
	if (!(alloc = malloc(sizeof(char) * len)))
		return (NULL);
	ft_bzero(alloc, (size_t)len);
	while (i < (len - 1) && s1[i] != '\n' && s1[i] != '\0')
	{
		alloc[i] = s1[i];
		i++;
	}
	return (alloc);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*alloc;
	int		len;
	int		i;
	int		j;

	alloc = NULL;
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(alloc = malloc(sizeof(char) * len)))
		return (NULL);
	ft_bzero(alloc, (size_t)len);
	while ((s1[i]) && i < ft_strlen(s1))
	{
		alloc[i] = s1[i];
		i++;
	}
	while (s2[j] && i < (len - 1))
	{
		alloc[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	return (alloc);
}

int				get_next_line(int fd, char **line)
{
	static char	*str;
	ssize_t		rd;
	char		buff[BUFFER_SIZE + 1];

	if (fd <= -1 || !line || BUFFER_SIZE <= 0)
	{
		printf("return -1\n");
		return (-1);
	}
	if ((rd = read(fd, buff, BUFFER_SIZE)) == -1)
		return (-1);
	(!str) ? str = ft_strdup("") : 0;
	ft_bzero(buff, BUFFER_SIZE + 1);
	while ((!ft_strchr(str, 10)) && ((rd = read(fd, buff, BUFFER_SIZE))))
	{
		str = ft_strjoin(str, buff);
		ft_bzero(buff, BUFFER_SIZE + 1);
	}
	*line = ft_strdup(str);
	str = ft_where_is_nl(str);
	if (rd == 0 /*&& ft_where_is_nl(str) == NULL*/)
	{
		free(str);
		str = NULL;
		return (0);
	}
	printf("[1]%s\n", *line);
	return (1);
}
