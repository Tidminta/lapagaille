/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 22:30:24 by tidminta          #+#    #+#             */
/*   Updated: 2020/01/17 19:12:35 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	**ft_free(char **tab, int len)
{
	if (**tab != '\0')
	{
		while (len >= 0)
		{
			free(tab[len]);
			tab[len] = NULL;
			len--;
		}
		free(tab);
		tab = NULL;
	}
	return (tab);
}

static int	ln(const char *s, char c)
{
	int	i;
	int	line;

	line = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		line++;
	}
	printf("LINE = %d\n", line);
	return (line);
}

static int	lt(char const *s, int i, char c)
{
	int	j;

	j = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		j++;
	}
	return (j);
}

// /*tab = (char **)malloc(sizeof(tab) * (ln(s, c) + 1));*/
// char	**cut(char ***tab, const char *s, char c)
// {
// 	if (!s || !c)
// 		return (NULL);
// 	*tab = ft_calloc((size_t)ln(s, c) + 1, sizeof(*tab));
// 	if (!tab)
// 		return (NULL);
// 	return (*tab);
// }

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	tab = (char **)ft_calloc(sizeof(tab), (ln(s, c) + 1));
	if (!tab)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			k = 0;
			tab[j] = (char *)ft_calloc(sizeof(char), (lt(s, i, c) + 1));
			if (!tab[j])
				return (ft_free(tab, j));
			while (s[i] != '\0' && (char)s[i] != c)
				tab[j][k++] = s[i++];
			tab[j++][k] = '\0';
		}
	}
	return (tab);
}
