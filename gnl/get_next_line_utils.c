/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:15:32 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/08 22:46:33 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	write(1, "\n", 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
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

char	*ft_strchr(const char *s, int c)
{
	while ((*s && *s != (char)c))
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

int		ft_where_is_nl(char *str)
{
	int i;
	int	nl;

	nl = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			nl++;
	}
	if (nl == 1)
	{
		while (str[i] && str[i] != '\n')
			i++;
		if (str[i] && str[i] == '\n')
			return (i);
	}
	else
	{
		
	}
	return (0);
}
