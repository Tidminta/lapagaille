/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 22:30:24 by tidminta          #+#    #+#             */
/*   Updated: 2020/01/15 02:52:27 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_is_present(char const *s, unsigned int *index, char c)
{
	if (s[*index] && s[*index] == c)
		return (1);
	else
		return (0);
}

static unsigned int	ft_words(char const *s, char c)
{
	unsigned int i;
	unsigned int words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (ft_is_present(s, &i, c) == 0)
		{
			words++;
			while ((s[i]) && (ft_is_present(s, &i, c) == 0))
				i++;
		}
		else
			while ((s[i]) && (ft_is_present(s, &i, c) == 1))
				i++;
	}
	return (words);
}

static size_t		ft_sub2(char const *s, unsigned int *i, char c)
{
	size_t	len;

	len = 0;
	while (s[*i] && ft_is_present(s, i, c) == 1)
	{
		*i += 1;
	}
	while (s[*i] && ft_is_present(s, i, c) == 0)
	{
		*i += 1;
		len++;
	}
	return (len);
}

static char			*ft_sub3(char const *s, unsigned int start, size_t len,
	char c)
{
	char	*alloc;
	size_t	i;

	i = -1;
	alloc = NULL;
	if (!s || !(alloc = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_bzero(alloc, (len + 1));
	while (ft_is_present(s, &start, c) == 1)
		start++;
	while ((++i < len) && (s[start]) && ft_is_present(s, &start, c) == 0)
	{
		alloc[i] = s[start];
		start++;
	}
	return (alloc);
}

char				**ft_split(char const *s, char c)
{
	char			**tab;
	unsigned int	words;
	unsigned int	i;
	unsigned int	j;

	if (!s || !c)
		return (NULL);
	words = ft_words(s, c);
	i = 0;
	j = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (j < words)
	{
		if (!(tab[j] = ft_sub3(s, i, ft_sub2(s, &i, c), c)))
		{
			while (j--)
				free(tab[j]);
			return (0);
		}
		j++;
	}
	tab[words] = 0;
	return (tab);
}
