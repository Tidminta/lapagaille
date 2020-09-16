/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:16:32 by tidminta          #+#    #+#             */
/*   Updated: 2020/09/16 19:07:03 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void		ft_sprites_projection2(t_mapinfos *map)
{
	int			y;
	int			color;
	t_player	*p;
	t_infosprt	*sp;

	y = 0;
	p = map->p;
	sp = map->spinfos;
	sp->spwidth = abs((int)(map->win_h / sp->transy));
	sp->startx = -sp->spwidth / 2 + sp->spscreenx;
	sp->startx = (sp->startx < 0) ? 0 : sp->startx;
	sp->endx = sp->spwidth / 2 + sp->spscreenx;
	sp->endx = (sp->endx < 0) ? map->win_h - 1 : sp->endx;
	sp->stripe = sp->startx;
	while (sp->stripe < sp->endx)
	{
		sp->texx = (int)(256 * (sp->stripe - (sp->spwidth / 2 + sp->spscreenx))
			* TEXWIDTH / sp->spwidth) / 256;
		if (sp->transy > 0 && sp->stripe > 0 && sp->stripe < map->res->x
			&& sp->transy < p->zbuff[sp->stripe])
		{
			y = sp->starty;
			while (y < sp->endy)
			{
				sp->d = (y) * 256 - map->win_h * 128 + sp->spheight * 128;
				sp->texy = ((sp->d * TEXHEIGHT) / sp->spheight) / 256;
				color = map->text[4]->data[TEXWIDTH * sp->texy * sp->texx];
				if ((color & 0x00FFFFFF) != 0)
					map->mlx->img->data[(int)(y * sp->stripe)] = color;
			}
		}
	}
}

void			ft_sprites_projections(t_mapinfos *map)
{
	t_player	*p;
	t_infosprt	*sp;
	int			nb;

	p = map->p;
	sp = map->spinfos;
	nb = -1;
	while (++nb < map->nbsp)
	{
		sp->spx = sp->sp[nb]->x - p->posx;
		sp->spy = sp->sp[nb]->y - p->posy;
		sp->invdet = 1.0 / (p->planx * p->diry - p->dirx * p->plany);
		sp->transx = sp->invdet * (p->diry * sp->spx - p->dirx * sp->spx);
		sp->transy = sp->invdet * (-p->plany * sp->spx + p->plany * sp->spy);
		sp->spscreenx = ((int)map->res->x / 2) * (1 + sp->transx / sp->transy);
		sp->spheight = abs((int)(map->win_h / sp->transy));
		sp->starty = -sp->spheight / 2 + map->win_h / 2;
		sp->starty = (sp->starty < 0) ? 0 : sp->starty;
		sp->endy = sp->spheight / 2 + map->win_h / 2;
		sp->endy = ((size_t)sp->endy >= map->win_h) ? map->win_h - 1 : sp->endy;
		ft_sprites_projection2(map);
	}
}

