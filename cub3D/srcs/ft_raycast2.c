/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 14:08:59 by tidminta          #+#    #+#             */
/*   Updated: 2020/07/06 16:30:48 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		ft_create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}


void		ft_draw_wall(t_mapinfos *map, t_player *player)
{
	int *tab;
	int x;
	int y;
	
	x = player->x;
	y = 0;
	tab = map->mlx->img->data;
	while (y <= player->drawstart)
	{
		printf("[plafond][x = %d][y = %d]\n", player->x, y);
		tab[y * map->win_w * x] = map->ceil_rgb;
		y++;
	}
	while (y <= player->drawend)
	{
		printf("[mur][x = %d][y = %d]\n", player->x, y);
		tab[y * map->win_w * x] = ft_create_trgb(0, 50, 50, 50);
		y++;
	}
	while (y < ((int)map->win_h))
	{
		printf("[sol][x = %d][y = %d]\n", player->x, y);
		tab[y * WIN_WIDTH * x] = map->floor_rgb;
		y++;
	}
}