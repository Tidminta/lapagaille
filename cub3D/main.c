/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:42:32 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/22 20:08:50 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include "mlx/mlx.h"

int		main(int ac, char **av)
{
	int			fd;
	t_list		*list;
	t_mapinfos	*map;
	t_mlx		mlx;
	// t_img		img;

	if (ac == 2)
	{
		list = NULL;
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			ft_printf("Error\nMap open failed\n");
			return (0);
		}
		if (!ft_parseinfos(&list, &map, fd))
		{
			ft_printf("Error\nMap parsing failed\n");
			return (0);
		}
		close(fd);
		mlx.mlx_ptr = mlx_init();
		mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "mlx42");
		mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
		mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l, &mlx.img.endian);
		map_render(&mlx.img.data, map->map_tab, map);
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
		mlx_loop(mlx.mlx_ptr);
		// system("leaks Cub3D"); 
		return (0);
	}
	ft_printf("Error\nInvalide number of arguments!\n");
	return (0);
}
