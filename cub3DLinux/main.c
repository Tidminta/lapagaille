/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:42:32 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/26 19:18:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int		main(int ac, char **av)
{
	int			fd;
	t_list		*list;
	t_mapinfos	*map;
	void		*mlx;
	void		*mlx_win;
	// void	(*del)(void*) = free;

	if (ac == 2)
	{
		list = NULL;
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			printf("Error\nMap open failed\n");
			return (0);
		}
		if (!ft_parseinfos(&list, &map, fd))
		{
			printf("Error\nMap parsing failed\n");
			return (0);
		}
		// ft_print_mapinfos(map);
		// ft_lstclear(&list, del);
		// ft_print_list(list);
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, 600, 600, "mlx42");
		mlx_loop(mlx);
		close(fd);
		system("leaks Cub3D");
		return (0);
	}
	printf("Error\nInvalide number of arguments!\n");
	return (0);
}
