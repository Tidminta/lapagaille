/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:56:23 by tidminta          #+#    #+#             */
/*   Updated: 2020/07/16 18:29:19 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/*
***************************************
**				RECAP                **
**				FIX SET FORARD       **
***************************************
*/

// int				ft_raycast(t_mapinfos **map_tmp, t_mlx *mlx, t_player *p)

void				ft_set_forward(t_mapinfos **map_tmp)
{
	char		**map2d;
	t_player	*p;
	t_mlx		*mlx2;
	t_mapinfos	*map;

	map = *map_tmp;
	p = *map->p;
	map2d = map->map_tab;
	mlx2 = map->mlx;
	if (map2d[(int)(p->posx + p->dirx * p->movespeed)][(int)p->posx] == '0')
		p->posx += p->dirx * p->movespeed;
	if (map2d[(int)p->posx][(int)(p->posy + p->diry * p->movespeed)] == '0')
		p->posy += p->diry * p->movespeed;
	ft_raycast(&map, map->mlx, p);
	// ft_print_playerinfos(p);
}
