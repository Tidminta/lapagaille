/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:37:57 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/13 20:01:22 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include <string.h>

#include <libc.h>
#include <stdlib.h>
#include <stdio.h>

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
		return (ft_strdup(""));
	if (start > ft_strlen(s))
	{
		// if (s)
		// 	free(s);
		return (ft_strdup(""));
	}
	if (!(tab = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);//return (ft_strdup(""));
	i = 0;
	while (s[start] != '\0' && i < len)
	{
		tab[i] = s[start + i];
		i++;
	}
	tab[i] = '\0';
	// free(s);
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
	if (s1[0] == '\n')
	{
		if (!(alloc = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		ft_bzero(alloc, 2);
		alloc[0] = '\n';
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
	printf("i = %i\n", i);
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
	(void)ac;
	(void)av;
	int i;

	i = 0;
	str = "\n";
	printf("str = [%s]\n", str);
	// system("leaks a.out");
	return (0);
}
