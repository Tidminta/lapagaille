/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 12:34:00 by tidminta          #+#    #+#             */
/*   Updated: 2020/07/04 12:39:16 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int			ft_parse_open2(char **av, t_mapinfos **map, t_list **list)
{
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nMap file open failed\n");
		return (fd);
	}
	if ((ft_parseinfos(list, map, fd)) <= 0)
	{
		ft_printf("Error\nMap parsing failed\n");
		return (-1);
	}
	// ft_print_mapinfos(*map);
	return (fd);
}

int				main(int ac, char **av)
{
	t_list		*list;
	t_mapinfos	*map;
	t_mlx		*mlx;
	int			fd;

	if (ac == 2)
	{
		list = NULL;
		mlx = NULL;
		if ((fd = ft_parse_open2(av, &map, &list)) < 0)
			return (0);
		ft_print_tab(map->map_tab);
	}
	return (0);
}
