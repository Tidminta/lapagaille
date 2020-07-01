/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:21:41 by tidminta          #+#    #+#             */
/*   Updated: 2020/07/01 19:19:03 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int			ft_parse_open(char **av, t_mapinfos **map, t_list **list)
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
	ft_print_mapinfos(*map);
	return (fd);
}

t_mlx		*ft_start_mlx(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	mlx->img = (t_img*)malloc(sizeof(t_img));
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "mlx42");
	mlx->img->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->img->data = (int *)mlx_get_data_addr(mlx->img->img_ptr, &mlx->img->bpp,
			&mlx->img->size_l, &mlx->img->endian);
	return (mlx);
}
