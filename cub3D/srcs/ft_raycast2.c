/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 14:08:59 by tidminta          #+#    #+#             */
/*   Updated: 2020/07/13 20:09:07 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		ft_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void		ft_clr(t_mapinfos *map, t_player *p)
{
	int x;
	int y;

	x = -1;
	(void)p;
	while (++x < (int)map->resolution->res_x)
	{
		y = -1;
		while (++y < (int)map->resolution->res_y - 1)
			map->mlx->img->data[y * map->resolution->res_x + x] = 0;
	}
}

void				ft_draw_all(t_mapinfos *map, t_player *p)
{
	int y;

	y = p->drawstart;
	if (p->x < (int)map->resolution->res_x - 1)
	{
		while (++y <= p->drawend)
			map->mlx->img->data[y * map->resolution->res_x + p->x] = 0x808080;
		while (++y < (int)map->resolution->res_y - 1)
			map->mlx->img->data[y * map->resolution->res_x + p->x] = map->floor_rgb;
	}
}
