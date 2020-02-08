/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:37:57 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/08 22:19:54 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

// // #include <libc.h>
// #include <stdlib.h>
// #include <stdio.h>

char		*ft_sstrdup(char *s1)
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
		ft_bzero(alloc, (size_t)len);
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

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	char	*str;

	str = ft_sstrdup("\nparis\n");
	printf("str = %s\n", str);
	free(str);
	str = NULL;
	// system("leaks a.out");
	return (0);
}
