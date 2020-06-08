/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 13:00:34 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/06 20:16:23 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/libftprintf.h"


// int	get_next_line(int fd, char **line);
// void ft_lstadd_back(t_list **alst, t_list *new);

void	ft_print_list(t_list *map)
{
	ft_printf("************ LIST ************\n");
	while (map->next)
	{
		printf("[%s]\n", map->content);
		map = map->next;
	}
}
t_list		*ft_parsemap(int fd)
{
	int 		ret;
	t_list		*map;
	t_list		*tmp;
	char 		*line;

	while ((ret = get_next_line(fd, &line)) == 1)
	{
		tmp = ft_lstnew((void*)line);
		ft_lstadd_front(&map, tmp);
	}
	return (map);
}