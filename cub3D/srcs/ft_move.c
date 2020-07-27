/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:56:23 by tidminta          #+#    #+#             */
/*   Updated: 2020/07/27 20:18:58 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/*
***************************************
**				RECAP                **
**				FIX SET FORARD       **
***************************************
*/

static void				ft_forwards(t_mapinfos **map_tmp)
{
	t_player	*p;
	t_mapinfos	*map;
	char		**map2d;

	map = *map_tmp;
	p = map->p;
	map2d = map->map_tab;
	if (map2d[(int)(p->posy + p->diry * p->movespeed)][(int)p->posx] == '0')
		p->posy += (p->diry) * p->movespeed;
	if (map2d[(int)p->posy][(int)(p->posx + p->dirx * p->movespeed)] == '0')
		p->posx += (p->dirx) * p->movespeed;
}

static void				ft_backwards(t_mapinfos **map_tmp)
{
	t_player	*p;
	t_mapinfos	*map;
	char		**map2d;

	map = *map_tmp;
	p = map->p;
	map2d = map->map_tab;
	if (map2d[(int)(p->posy - p->diry)][(int)p->posx])
		p->posy -= (p->diry) * p->movespeed;
	if (map2d[(int)p->posy][(int)(p->posx - p->dirx)])
		p->posx -= (p->dirx) * p->movespeed;
}

static void		ft_right_rot(t_mapinfos **map_tmp)
{
	t_player	*p;
	t_mapinfos	*map;

	map = *map_tmp;
	p = map->p;
	p->odirx = p->dirx;
	// p->rotspeed = (sign < 0) ? (p->rotspeed * sign) : p->rotspeed;
	p->dirx = p->dirx * cos(-p->rotspeed) - p->diry * sin(-p->rotspeed);
	p->diry = p->odirx * sin(-p->rotspeed) + p->diry * cos(-p->rotspeed);
	p->oplanx = p->planx;
	p->planx = p->planx * cos(-p->rotspeed) - p->plany * sin(-p->rotspeed);
	p->plany = p->oplanx * sin(-p->rotspeed) + p->plany * cos(-p->rotspeed);
}

static void		ft_left_rot(t_mapinfos **map_tmp)
{
	t_player	*p;
	t_mapinfos	*map;

	map = *map_tmp;
	p = map->p;
	p->odirx = p->dirx;
	// p->rotspeed = (sign < 0) ? (p->rotspeed * sign) : p->rotspeed;
	p->dirx = p->dirx * cos(p->rotspeed) - p->diry * sin(p->rotspeed);
	p->diry = p->odirx * sin(p->rotspeed) + p->diry * cos(p->rotspeed);
	p->oplanx = p->planx;
	p->planx = p->planx * cos(p->rotspeed) - p->plany * sin(p->rotspeed);
	p->plany = p->oplanx * sin(p->rotspeed) + p->plany * cos(p->rotspeed);
}

int				ft_setmove(t_mapinfos **map_tmp)
{
	t_mapinfos	*map;
	t_player	*p;
	t_mlx		*mlx2;

	map = *map_tmp;
	p = map->p;
	mlx2 = map->mlx;
	if (p->m_up)
		ft_forwards(&map);
	else if (p->m_down)
		ft_backwards(&map);
	else if (p->m_left)
		ft_left_rot(&map);
	else if (p->m_right)
		ft_right_rot(&map);
	return (0);
}

int				ft_keypress(int key, t_mapinfos **map_tmp)
{
	t_mapinfos	*map;
	t_player	*p;
	t_mlx		*mlx2;

	map = *map_tmp;
	p = map->p;
	mlx2 = map->mlx;
	if (key == 13 || key == 126)
		p->m_up = 1;
	else if (key == 1 || key == 125)
		p->m_down = 1;
	else if (key == 0 || key == 123)
		p->m_left = 1;
	else if (key == 2 || key == 124)
		p->m_right = 1;
	else if (key == 53)
	{
		printf("ECHAP\n");
		mlx_destroy_window(map->mlx->mlx_p, map->mlx->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int				ft_keyrelease(int key, t_mapinfos **map_tmp)
{
	t_mapinfos	*map;
	t_player	*p;
	t_mlx		*mlx2;

	map = *map_tmp;
	p = map->p;
	mlx2 = map->mlx;
	if (key == 13 || key == 126)
		p->m_up = 0;
	else if (key == 1 || key == 125)
		p->m_down = 0;
	else if (key == 0 || key == 123)
		p->m_left = 0;
	else if (key == 2 || key == 124)
		p->m_right = 0;
	return (0);
}
