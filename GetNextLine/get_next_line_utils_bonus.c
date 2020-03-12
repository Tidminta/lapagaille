/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:15:01 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/24 21:17:30 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	char *dst;

	dst = s;
	while (n-- > 0)
	{
		*dst = '\0';
		dst++;
	}
	return ;
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while ((*s && *s != (char)c))
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_where_is_nl(char *s)
{
	char	*alloc;
	char	*tmp;
	int		i;

	i = 0;
	alloc = NULL;
	tmp = NULL;
	if (!s)
		return (NULL);
	tmp = s;
	while ((tmp[i]) && tmp[i] != '\n')
		i++;
	if (tmp[i] && tmp[i] == '\n')
	{
		if (!(alloc = ft_substr(s, i + 1, ft_strlen(s) - i)))
			return (NULL);
		free(s);
		s = NULL;
		return (alloc);
	}
	free(s);
	s = NULL;
	return (NULL);
}
