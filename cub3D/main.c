/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:42:32 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/09 12:31:15 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include "includes/libft.h"

int		main(int ac, char **av)
{
	int			fd;
	t_list		*list;
	t_mapinfos	*map;

	if (ac == 2)
	{
		list = (t_list *)malloc(sizeof(t_list));
		map = (t_mapinfos *)malloc(sizeof(t_mapinfos));
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			ft_printf("Error\nMap open failed\n");
			return (0);
		}
		if (!ft_parsemap(list, map, fd))
		{
			ft_printf("Error\nMap parsing failed\n");
			return (0);
		}
		free(list);
		free(map->resolution);
		free(map->floor);
		free(map->ceil);
		free(map->no);
		free(map->so);
		free(map->ea);
		free(map->we);
		free(map->sprite);
		free(map);
		close(fd);
		system("leaks Cub3D");
		return (0);
	}
	ft_printf("Error\nInvalide number of arguments!\n");
	return (0);
}
