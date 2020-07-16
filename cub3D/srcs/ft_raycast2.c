/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 14:08:59 by tidminta          #+#    #+#             */
/*   Updated: 2020/07/16 18:49:15 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int				ft_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static void		ft_clr_win(t_mapinfos *map)
{
	size_t	x;
	size_t	y;

	y = -1;
	while (++y < map->res->y)
	{
		x = -1;
		while (++x < map->res->x)
			map->mlx->img->data[y * map->res->x + x] = 0x0;
	}
}

int				ft_deal_key(int key, t_mapinfos *map)
{
	t_player	*p;
	t_mlx		*mlx2;

	p = *map->p;
	mlx2 = map->mlx;
	if (key == 13)
	{
		ft_clr_win(map);
		ft_set_forward(&map);
	}
	else if (key == 53)
	{
		ft_printf("ECHAP\n");
		mlx_destroy_window(map->mlx->mlx_p, map->mlx->win);
		exit(EXIT_SUCCESS);
	}
	else
		printf("[KEY][%d]\n", key);
	return (0);
}

int				ft_do_thejob(t_mapinfos **map_tmp)
{
	t_mapinfos *map;

	map = *map_tmp;
	ft_raycast(map_tmp, map->mlx, *map->p);
	mlx_key_hook(map->mlx->win, ft_deal_key, map);
	mlx_loop(map->mlx->mlx_p);
	return (0);
}
