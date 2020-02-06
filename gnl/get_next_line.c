/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:15:23 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/06 03:30:18 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// static int		ft_after(char *str)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	while (str[i] && str[i] != '\n')
// 	{
// 		i++;
// 	}
// 	while (str[i] != '\0')
// 	{
// 		i++;
// 		j++;
// 	}
// 	return (j);
// }
int				get_next_line(int fd, char **line)
{
	static char		*str;
	char			buff[BUFF_SIZE + 1];
	ssize_t			rd;
	// char			*tmp;

	if (!str)
		str = ft_strdup("");
	printf("[debut]str = %s\n", str);
	while ((!ft_strchr(buff, 10)) && (rd = read(fd, buff, BUFF_SIZE) > 0))
	{
		buff[BUFF_SIZE] = '\0';
		str = ft_strjoin(str, buff);
		// printf("[boucle]str = %s\n", str);
	}
	if (rd == 0)
	{
		if (!(*line = ft_strdup(str)))
			return (-1);
		return (0);
	}
	if (!(*line = ft_strdup(str)))
		return (-1);
	str = ft_strchr(str, 10) + 1;
	return (1);
}
