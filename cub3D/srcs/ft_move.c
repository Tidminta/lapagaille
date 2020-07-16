/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:56:23 by tidminta          #+#    #+#             */
/*   Updated: 2020/07/16 17:21:28 by tidminta         ###   ########.fr       */
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

void				ft_set_forward(t_mapinfos *map)
{
	char		**map2d;
	t_player	*p;
	t_mlx		*mlx2;

	p = *map->p;
	map2d = map->map_tab;
	mlx2 = map->mlx;
	if (map2d[(int)(p->posx + p->dirx * p->movespeed)][(int)p->posx] == '0')
		p->posx += p->dirx * p->movespeed;
	if (map2d[(int)p->posx][(int)(p->posy + p->diry * p->movespeed)] == '0')
		p->posy += p->diry * p->movespeed;
	ft_raycast(&map, map->mlx, p);
	ft_print_playerinfos(p);
	mlx_put_image_to_window(mlx2->mlx_p, mlx2->win, mlx2->img->img_p, 0, 0);
}
