/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidiane <tidiane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:06:34 by tidiane           #+#    #+#             */
/*   Updated: 2023/02/09 01:52:42 by tidiane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(char *str)
{
    size_t  i;

    i = 0;
    if (!str)
        return (0);
    while (str[i] && str[i] != '\0')
        i++;
    return (i);
}

char    *ft_strdup(char *str)
{
    char    *new;
    int     i;

    i = 0;
    if (!str[i])
        return (NULL);
    while (str[i] && str[i] != '\n')
        i++;
    new = (char*)malloc(sizeof(char) * (i + 2));
    if (!new)
        return (NULL);
    i = 0;
    while (str[i] && str[i] != '\n')
    {
        new[i] = str[i];
        i++;
    }
    if (str[i] == '\n')
    {
        new[i] = str[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}

char    *ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
