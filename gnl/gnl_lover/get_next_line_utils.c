/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:15:32 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/18 16:46:17 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// void		ft_check_params(int fd, char **line)
// {
// 	ssize_t ret;

// 	if (fd <= -1 || !line || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	ft_bzero(*buff, BUFFER_SIZE + 1);
// 	if ((ret = read(fd, *buff, BUFFER_SIZE)) == -1)
// 		return (NULL);
// 	if (!*str)
// 		*str = ft_strdup("");
// 	if (!(*str = ft_strjoin(*str, *buff)))
// 		return (NULL);
// 	ft_bzero(*buff, BUFFER_SIZE + 1);//peut etre a supp
// 	return (*str);
// }

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
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
	int		i;

	i = 0;
	alloc = NULL;
	if (!s)
		return (NULL);
	while ((s[i] && s[i] != '\n'))
		i++;
	if (s[i] == '\n')
	{
		if (!(alloc = (char *)malloc(sizeof(char) * (ft_strlen(s) - i))))
			return (NULL);
		alloc = ft_substr(s, i + 1, ft_strlen(s) - i);
		return (alloc);
	}
	return (NULL);
}
