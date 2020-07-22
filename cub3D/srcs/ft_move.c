/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:56:23 by tidminta          #+#    #+#             */
/*   Updated: 2020/07/22 18:08:10 by tidminta         ###   ########.fr       */
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
	if (map2d[(int)(p->posx + p->dirx)][(int)p->posx] == '0')
		p->posx += (p->dirx) * p->movespeed;
	if (map2d[(int)p->posx][(int)(p->posy + p->diry)] == '0')
		p->posy += (p->diry) * p->movespeed;
}

static void				ft_backwards(t_mapinfos **map_tmp)
{
	t_player	*p;
	t_mapinfos	*map;
	char		**map2d;

	map = *map_tmp;
	p = map->p;
	map2d = map->map_tab;
	if (map2d[(int)(p->posx - p->dirx)][(int)p->posx])
		p->posx -= (p->dirx) * p->movespeed;
	if (map2d[(int)p->posx][(int)(p->posy - p->diry)])
		p->posy -= (p->diry) * p->movespeed;
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

int				ft_dealkey(int key, t_mapinfos **map_tmp)
{
	t_mapinfos *map;
	t_player	*p;
	t_mlx		*mlx2;

	map = *map_tmp;
	p = map->p;
	mlx2 = map->mlx;
	if (key == 13 || key == 126)
	{
		ft_forwards(&map);
		printf("[key pressed][W]\n");
	}
	else if (key == 1 || key == 125)
	{
		ft_backwards(&map);
		printf("[key pressed][S]\n");
	}
	else if (key == 0 || key == 123)
	{
		ft_left_rot(&map);
		printf("[key pressed][A]\n");
	}
	else if (key == 2 || key == 124)
	{
		ft_right_rot(&map);
		printf("[key pressed][D]\n");
	}
	else if (key == 53)
	{
		printf("ECHAP\n");
		mlx_destroy_window(map->mlx->mlx_p, map->mlx->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}