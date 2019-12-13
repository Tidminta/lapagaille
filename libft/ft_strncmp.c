/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 18:01:33 by tidminta          #+#    #+#             */
/*   Updated: 2019/12/13 20:14:26 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		return (0);
	while ((s1[i] == s2[i]) && (i < n - 1) && (s1[i] && s2[i]))
	{
		// printf("s1[%zu] = %c\ns2[%zu] = %c\n", i, s1[i], i, s2[i]);
		i++;
	}
	// printf("F\ns1[%zu] = %c\ns2[%zu] = %c\n", i, s1[i], i, s2[i]);
	if (s1[i] != s2[i])
	{
		printf("s1[i] : %c\ns2[i] = %c\ncmp = %i\n", s1[i], s2[i], s1[i] - s2[i]);
		return (s1[i] - s2[i]);
	}
	return (0);
}
