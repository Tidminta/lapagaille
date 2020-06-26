/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:25:42 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/04 18:39:19 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*tab;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (!(tab = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (s[start] != '\0' && i < len)
	{
		tab[i] = s[start + i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
