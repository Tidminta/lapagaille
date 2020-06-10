/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:43:45 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/10 12:28:26 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include "includes/libft.h"

size_t		ft_parsemap2(t_list **list, t_mapinfos **map, int fd)
{
	(void)map;
	*list = ft_map_gnl(fd);
	return (1);
}

int		main(int ac, char **av)
{
	int			fd;
	t_list		*list;
	t_mapinfos	*map;
	void		(*del)(void*) = free;
	char 		*str;

	if (ac == 2)
	{
		list = NULL;
		map = NULL;
		if ((fd = open(av[1], O_RDONLY)) == -1)
		{
			ft_printf("Error\nMap open failed\n");
			return (0);
		}
		if (!ft_parsemap2(&list, &map, fd))
		{
			ft_printf("Error\nMap parsing failed\n");
			return (0);
		}
		ft_print_list(list);
		ft_lstclear(&list, del);
		printf("")
	}
	system("leaks a.out");
	return (0);
}
