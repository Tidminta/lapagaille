/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:25:42 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/04 18:57:28 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_substr2(char const *s, size_t start, size_t len)
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
