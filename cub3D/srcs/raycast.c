/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:10:15 by tidminta          #+#    #+#             */
/*   Updated: 2020/10/07 18:47:39 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void		ft_step_init(t_mapinfos *map, t_player *p)
{
	double		tern;

	p->camx = 2 * p->x / (double)map->res->x - 1;
	p->raydx = p->dirx + p->planx * p->camx;
	p->raydy = p->diry + p->plany * p->camx;
	p->mapx = (int)p->posx;
	p->mapy = (int)p->posy;
	p->deltadx = fabs(1 / p->raydx);
	p->deltady = fabs(1 / p->raydy);
	tern = (p->raydx == 0) ? 1 : fabs(1 / p->raydx);
	p->deltadx = (p->raydy == 0) ? 0 : tern;
	tern = (p->raydy == 0) ? 1 : fabs(1 / p->raydy);
	p->deltady = (p->raydx == 0) ? 0 : tern;
	p->stepx = (p->raydx < 0) ? -1 : 1;
	if (p->raydx < 0)
		p->sidedx = (p->posx - p->mapx) * p->deltadx;
	else
		p->sidedx = (p->mapx + 1.0 - p->posx) * p->deltadx;
	p->stepy = (p->raydy < 0) ? -1 : 1;
	if (p->raydy < 0)
		p->sidedy = (p->posy - p->mapy) * p->deltady;
	else
		p->sidedy = (p->mapy + 1.0 - p->posy) * p->deltady;
}

/*
*************************************
**			  D D A                **
**		PERPWALLDIST CALCULS       **
*************************************
*/

static void		ft_dda(t_player *p, char **map2d)
{
	while (p->hit == 0)
	{
		if (p->sidedx < p->sidedy)
		{
			p->sidedx += p->deltadx;
			p->mapx += p->stepx;
			p->side = 0;
		}
		else
		{
			p->sidedy += p->deltady;
			p->mapy += p->stepy;
			p->side = 1;
		}
		if (map2d[p->mapy][p->mapx] == '1')
			p->hit = 1;
	}
	if (p->side == 0)
		p->perpwd = (p->mapx - p->posx + (1 - p->stepx) / 2) / p->raydx;
	else
		p->perpwd = (p->mapy - p->posy + (1 - p->stepy) / 2) / p->raydy;
}

/*
*************************************
**			WALL DRAWING	       **
*************************************
*/

static void		ft_drawall(t_mapinfos *map, t_player *p, t_mlx *mlx)
{
	int			y;

	p->lineheight = (int)(map->res->y / p->perpwd);
	p->drawstart = -p->lineheight / 2 + map->res->y / 2;
	if (p->drawstart < 0)
		p->drawstart = 0;
	p->drawend = p->lineheight / 2 + map->res->y / 2;
	if (p->drawend >= (int)map->res->y)
		p->drawend = map->res->y - 1;
	y = 0;
	while (y++ <= p->drawstart)
		mlx->img->data[(int)(y * map->res->x + p->x)] = map->ceil_rgb;
	y = p->drawend;
	while (y++ < (int)map->res->y - 1)
		mlx->img->data[(int)(y * map->res->x + p->x)] = map->floor_rgb;
}

int				ft_raycast(t_mapinfos *map, t_mlx *mlx, t_player *p)
{
	char		**map2d;

	map2d = map->map_tab;
	p->posx = (p->posx == 0) ? map->start_x : p->posx;
	p->posy = (p->posy == 0) ? map->start_y : p->posy;
	p->x = 0;
	while (p->x < (int)map->res->x)
	{
		p->hit = 0;
		ft_step_init(map, p);
		ft_dda(p, map->map_tab);
		ft_drawall(map, p, mlx);
		ft_drawtext(map, mlx);
		p->zbuff[p->x] = p->perpwd;
		p->x += 1;
	}
	return (0);
}
