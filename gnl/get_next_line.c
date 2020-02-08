/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:15:23 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/08 21:23:17 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*tab;
	int		i;

	if (!s || start < 0)
		return (ft_strdup(""));
	if (start > ft_strlen(s))
	{
		if (s)
			free(s);
		return (ft_strdup(""));
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
	len = ft_strlen(s1) + 1;
	if (s1[0] == 0)
	{
		if (!(alloc = malloc(sizeof(char))))
			return (NULL);
		alloc[0] = '\0';
		return (alloc);
	}
	if (!(alloc = malloc(sizeof(char) * len)))
		return (NULL);
	ft_bzero(alloc, (size_t)len);
	while (i < (len - 1) && s1[i] != '\n')
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
	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (ft_strdup(""));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(alloc = malloc(sizeof(char) * len)))
		return (NULL);
	while (i < len)
	{
		alloc[i] = '\0';
		i++;
	}
	i = 0;
	while ((s1[i]) && i < ft_strlen(s1))
	{
		alloc[i] = s1[i];
		i++;
	}
	while (i < (len - 1))
	{
		alloc[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	return (alloc);
}

int				get_next_line(int fd, char **line)
/*modifier ft_strdup pour qu'il puisse copier si il n'ya qu'un seul \n
ou bien faire une fonction de check de str juste avant la separion [line/str]*/
{
	static char	*str;
	ssize_t		rd;
	char		buff[BUFF_SIZE + 1];
	int			where;

	if (!str)
		str = ft_strdup("");
	printf("[debut]str = %s\n", str);
	while ((!ft_strchr(buff, 10)) && ((rd = read(fd, buff, BUFF_SIZE)) > 0))
	{
		buff[BUFF_SIZE] = '\0';
		str = ft_strjoin(str, buff);
		printf("[boucle rd = %zd]str = %s\n", rd, str);
	}
	*line = ft_strdup(str);
	where = ft_where_is_nl(str);
	str = ft_substr(str, where, ft_strlen(str));
	printf("[fin]line = %s\nstr = %s\n", *line, str);
	if (rd <= 0)
		return (0);
	return (1);
}
