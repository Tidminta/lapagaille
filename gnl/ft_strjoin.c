/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 22:46:48 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/05 22:47:47 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strjoin(const char *s1, const char *s2)
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
	return (alloc);
}
