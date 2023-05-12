/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 22:30:24 by tidminta          #+#    #+#             */
/*   Updated: 2023/02/09 11:00:24 by tminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_free(char **tab, int len)
{
	if (tab[0][0] != '\0')
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

static int		ln(const char *s, char c)
{
	int	i;
	int line;

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
	return (line);
}

static int		lt(char const *s, int i, char c)
{
	int j;

	j = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		j++;
	}
	return (j);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	j = 0;
	if ((!s || !(tab = (char **)malloc(sizeof(tab) * (ln(s, c) + 1)))))
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			k = 0;
			if (!(tab[j] = (char *)malloc(sizeof(char) * (lt(s, i, c) + 1))))
				return (ft_free(tab, j));
			while (s[i] != '\0' && (char)s[i] != c)
				tab[j][k++] = s[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = 0;
	return (tab);
}
