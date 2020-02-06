/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:37:57 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/06 03:12:06 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
// #include <libc.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
	while (++i < (len - 1))
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
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	printf("len = %i\n", len);
	if (!(alloc = malloc(sizeof(char) * len)))
		return (NULL);
	while (++i < len)
		alloc[i] = '\0';
	i = -1;
	while (++i < ft_strlen(s1))
		alloc[i] = s1[i];
	while (i < (len - 1))
		alloc[i++] = s2[++j];
	return (alloc);
}

int		main(void)
{
	char	*str;
	char	*tmp;

	tmp = "paris est magique";
	str = ft_strdup(tmp + 5);
	printf("str = %s\n", str);
	free(str);
	return (0);
}
