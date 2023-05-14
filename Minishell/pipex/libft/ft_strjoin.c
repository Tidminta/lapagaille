/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tminta <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:53:38 by tminta            #+#    #+#             */
/*   Updated: 2022/07/07 15:53:46 by tminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		i;
	int		lenght;

	if (!s1 || !s2)
		return (NULL);
	lenght = ft_strlen(s1) + ft_strlen(s2);
	tab = (char *)malloc(sizeof(char) * (lenght + 1));
	if (!tab)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		tab[i] = s1[i];
	i = 0;
	lenght = lenght - ft_strlen(s2);
	while (s2[i] != '\0')
	{
		tab[lenght] = s2[i];
		i++;
		lenght++;
	}
	tab[lenght] = '\0';
	return (tab);
}
