/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidiane <tidiane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:06:31 by tidiane           #+#    #+#             */
/*   Updated: 2023/02/09 01:52:39 by tidiane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char    *ft_strjoin(char *s1, char *s2)
{
	char			*alloc;
	size_t          i;
	size_t          j;

	i = 0;
	j = 0;
	if (!s1)
    {
        s1 = (char*)malloc(sizeof(char) * 1);
        if (!s1)
            return (NULL);
        s1[0] = '\0';
    }
    if(!s1 || !s2)
        return (NULL);
	alloc = (char*)malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
    if (alloc == NULL)
		return (NULL);
    i = -1;
    j = 0;
    if (s1)
    {
        while (s1[++i] != '\0')
            alloc[i] = s1[i];
    }
    while (s2[j] != '\0')
		alloc[i++] = s2[j++];
    alloc[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (alloc);
}

char    *read_line(char *stat, int fd)
{
    char        *buff;
    int         hbr;

    buff = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buff)
        return (NULL);
    hbr = 1;
    while (!ft_strchr(stat, '\n') && hbr != 0)
    {
        hbr = read(fd, buff, BUFFER_SIZE);
        if (hbr == -1)
        {
            free(buff);
            return (NULL);
        }
        buff[hbr] = '\0';
        stat = ft_strjoin(stat, buff);
    }
    free(buff);
    return (stat);
}

char *refactor_line(char *stat)
{
    char    *tmp;
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (stat[i] && stat[i] != '\n')
        i++;
    if (!stat[i])
    {
        free(stat);
        return (NULL);
    }
    tmp = (char*)malloc(sizeof(char) * (ft_strlen(stat) - i + 1));
    if (!tmp)
        return (NULL);
    i++;
    while (stat[i])
    {
        tmp[j] = stat[i];
        i++;
        j++;
    }
    tmp[j] = '\0';
    free(stat);
    return (tmp);
}

char    *get_next_line(int fd)
{
    static char		*stat;
	char			*line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    stat = read_line(stat, fd);
    if (!stat)
        return (NULL);
    line = ft_strdup(stat);
    stat = refactor_line(stat);
    return (line);
}
