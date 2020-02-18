/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:15:23 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/18 17:02:04 by tidminta         ###   ########.fr       */
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
	if (!s1 || s1[0] == '\0')
	{
		if (!(alloc = (char *)malloc(sizeof(char))))
			return (NULL);
		alloc[0] = '\0';
		return (alloc);
	}
	len = ft_strlen(s1);
	if (!(alloc = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_bzero(alloc, (size_t)len + 1);
	if (i == 0 && s1[i] == '\n')
	{
		alloc[i] = '\n';
		return (alloc);
	}
	while (s1[i] != '\0' && s1[i] != '\n')
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
	free(s1);// /!\ leaks
	s1 = NULL;
	return (alloc);
}

int				get_next_line(int fd, char **line)
{
	static char	*str;
	ssize_t		rd;
	char		buff[BUFFER_SIZE + 1];

	if (fd <= -1 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!str)
		str = ft_strdup("");
	ft_bzero(buff, BUFFER_SIZE + 1);
	rd = 1;
	while ((!ft_strchr(str, 10)) && ((rd = read(fd, buff, BUFFER_SIZE))))
	{
		if (rd == -1)
			return (-1);
		str = ft_strjoin(str, buff);
		ft_bzero(buff, BUFFER_SIZE + 1);
	}
	if (str)
	{
		*line = ft_strdup(str);
		str = ft_where_is_nl(str);//!\renvoi NULL quand aucun \n dans str
	}
	if (rd == 0 && str == NULL)
	{
		free(str);
		str = NULL;
		// printf("\n\n[if]\n\nstr = [%s]\nline = [%s]\n\n", str, *line);
		return (0);
	}
	// if (rd == 0)
	// 	return (0);
	return (1);
}
