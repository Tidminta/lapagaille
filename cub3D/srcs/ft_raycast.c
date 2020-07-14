/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:10:15 by tidminta          #+#    #+#             */
/*   Updated: 2020/07/14 17:53:36 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/*
 *************************************
 **			  FCTS                 **
 **	(DIRX/Y)?? |                   **
 **	DO FONCTION QUI SET DIRX/Y     **
 **	EN FONCTION DE N,S,E OU W      **
 **	RECAP : RAYCAST REFACT		   **
 ** 							   **
 *************************************
 */

static void		ft_step_init(t_mapinfos *map, t_player **p_tmp)
{
	t_player	*p;
	double		tern;

	p = *p_tmp;
	p->camx = 2 * p->x / (double)map->resolution->res_x - 1;
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

static void		ft_dda(t_player **player, char **map2d)
{
	t_player	*p;

	p = *player;
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

int				ft_raycast(t_mapinfos **map_tmp, t_mlx **mlx)
{
	char		**map2d;
	t_mapinfos	*map;
	t_player	*p;

	map = *map_tmp;
	map2d = map->map_tab;
	p = ft_playerinit();
	if (!p)
		return (-1);
	// map->mlx = *mlx;
	p->posx = map->start_x;
	p->posy = map->start_y;
	p->dirx = -1;
	p->diry = 0;
	while (p->x < (int)map->resolution->res_x)
	{
		p->hit = 0;
		ft_step_init(map, &p);
		ft_dda(&p, map->map_tab);
		ft_draw_all(map, &p);
		mlx_put_image_to_window(map->mlx->mlx_p, map->mlx->win, map->mlx->img->img_p, 0, 0);
		p->x += 1;
	}
	mlx_loop(map->mlx->mlx_p);
	return (0);
}
