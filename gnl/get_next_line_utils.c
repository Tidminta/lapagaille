/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:15:32 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/06 03:18:52 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	write(1, "\n", 1);
}

char		*ft_strchr(const char *s, int c)//si besoin enlever "const"
{
	int		i;
	char	match;

	i = 0;
	match = (char)c;
	while (*s && (*s != match))
		s++;
	if (*s == match)
		return ((char *)s);
	return (NULL);
}

char		*ft_strdup(char *s1)
{
	char	*alloc;
	int		i;
	int		len;

	i = -1;
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
	while (++i < len)
		alloc[i] = '\0';
	i = -1;
	while (++i < (len - 1) && s1[i] != '\n')
		alloc[i] = s1[i];
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
	j = -1;
	if (!s1 || !s2)
		return (ft_strdup(""));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(alloc = malloc(sizeof(char) * len)))
		return (NULL);
	while (++i < len)
		alloc[i] = '\0';
	i = -1;
	while (++i < ft_strlen(s1))
		alloc[i] = s1[i];
	while (i < (len - 1))
		alloc[i++] = s2[++j];
	// free(s1);
	return (alloc);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
