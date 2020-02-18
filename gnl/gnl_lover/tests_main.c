/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:37:57 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/18 16:25:01 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include <string.h>
#include <libc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

char	*ft_where_is_nl(char *s)
{
	char	*alloc;
	int		i;

	i = 0;
	alloc = NULL;
	if (!s)
		return (NULL);
	while ((s[i] && s[i] != '\n'))
		i++;
	if (s[i] == '\n')
	{
		if (!(alloc = (char *)malloc(sizeof(char) * (ft_strlen(s) - i))))
			return (NULL);
		alloc = ft_substr(s, i + 1, ft_strlen(s) - i);
		return (alloc);
	}
	return (NULL);
}

int		main(int ac, char **av)
{
	char *str;
	char *str2;
	(void)ac;
	(void)av;
	int i;

	i = 0;
	str2 = ft_strdup("0123456789\n000000000");
	str = ft_strdup("\n");
	printf("[%s]\n", str);
	printf("[%s]\n", str2);
	// system("leaks a.out");
	return (0);
}
