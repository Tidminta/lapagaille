/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:56:23 by tidminta          #+#    #+#             */
/*   Updated: 2020/07/28 16:00:36 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/*
***************************************
**				RECAP                **
**				FIX SET FORARD       **
***************************************
*/

static void				ft_up(t_mapinfos **map_tmp)
{
	t_player	*p;
	t_mapinfos	*map;
	char		**map2d;

	map = *map_tmp;
	p = map->p;
	map2d = map->map_tab;
	if (map2d[(int)(p->posy + p->diry * p->movespeed)][(int)p->posx] == '0')
		p->posy += p->diry * p->movespeed;
	if (map2d[(int)p->posy][(int)(p->posx + p->dirx * p->movespeed)] == '0')
		p->posx += p->dirx * p->movespeed;
}

static void				ft_down(t_mapinfos **map_tmp)
{
	t_player	*p;
	t_mapinfos	*map;
	char		**map2d;

	map = *map_tmp;
	p = map->p;
	map2d = map->map_tab;
	if (map2d[(int)(p->posy - p->diry)][(int)p->posx] == '0')
		p->posy -= ((p->diry) * p->movespeed);
	if (map2d[(int)p->posy][(int)(p->posx - p->dirx)] == '0')
		p->posx -= ((p->dirx) * p->movespeed);
}

static void				ft_rot(t_mapinfos **map_tmp, int s)
{
	t_player	*p;
	t_mapinfos	*map;

	map = *map_tmp;
	p = map->p;
	p->odirx = p->dirx;
	p->dirx = p->dirx * cos(s * p->rot_s) - p->diry * sin(s * p->rot_s);
	p->diry = p->odirx * sin(s * p->rot_s) + p->diry * cos(s * p->rot_s);
	p->oplanx = p->planx;
	p->planx = p->planx * cos(s * p->rot_s) - p->plany * sin(s * p->rot_s);
	p->plany = p->oplanx * sin(s * p->rot_s) + p->plany * cos(s * p->rot_s);
}

static int				ft_setmove2(t_mapinfos **map_tmp)
{
	t_mapinfos	*map;
	t_player	*p;
	t_mlx		*mlx2;

	map = *map_tmp;
	p = map->p;
	mlx2 = map->mlx;
	if (p->m_left)
		ft_rot(&map, 1);
	else if (p->m_right)
		ft_rot(&map, -1);
	return (0);
}

int						ft_setmove(t_mapinfos **map_tmp)
{
	t_mapinfos	*map;
	t_player	*p;
	t_mlx		*mlx2;

	map = *map_tmp;
	p = map->p;
	mlx2 = map->mlx;
	if (p->m_up)
		ft_up(&map);
	else if (p->m_down)
		ft_down(&map);
	else if (p->m_left)
		ft_rot(&map, 1);
	else if (p->m_right)
		ft_rot(&map, -1);
	ft_setmove2(map_tmp);
	return (0);
}
