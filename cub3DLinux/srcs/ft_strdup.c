/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:47:08 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/04 18:38:41 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*tab;
	int		len;
	int		i;

	len = 0;
	while (s1[len] != '\0')
		len++;
	if ((tab = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
