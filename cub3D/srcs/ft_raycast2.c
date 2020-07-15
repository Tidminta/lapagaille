/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 14:08:59 by tidminta          #+#    #+#             */
/*   Updated: 2020/07/15 19:23:47 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int			ft_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static void		ft_clr_win(t_mapinfos *map)
{
	size_t	x;
	size_t	y;
	t_mlx	*mlx;

	y = -1;
	mlx = map->mlx;
	while (++y < map->res->y)
	{
		x = -1;
		while (++x < map->res->x)
			map->mlx->img->data[y * map->res->x + x] = 0x0;
	}
}

int			ft_deal_key(int key, t_mapinfos *map)
{
	t_player	*p;

	p = *map->p;
	if (key == 124)
		ft_printf("[fleche droite]\n");
	else if (key == 13)
	{
		printf("W\n");
		ft_clr_win(map);
		// if (map->map_tab[(int)(p->posx + p->dirx)][(int)p->posx] == '0')
		// 	p->posx += p->dirx;
		// if (map->map_tab[(int)p->posx][(int)(p->posy + p->diry)] == '0')
		// 	p->posy += p->diry;
		// ft_raycast(&map, &map->mlx, p);
		mlx_put_image_to_window(map->mlx->mlx_p, map->mlx->win, map->mlx->img->img_p, 0, 0);
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
