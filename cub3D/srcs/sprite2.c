/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:16:32 by tidminta          #+#    #+#             */
/*   Updated: 2020/10/06 20:25:38 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void		ft_width_height(t_mapinfos *map, t_sprite **sp,
	t_player *p, int nb)
{
	sp[nb]->spx = sp[nb]->x - p->posx;
	sp[nb]->spy = sp[nb]->y - p->posy;
	sp[nb]->invdet = 1.0 / (p->planx * p->diry - p->dirx * p->plany);
	sp[nb]->transx = sp[nb]->invdet *
		(p->diry * sp[nb]->spx - p->dirx * sp[nb]->spy);
	sp[nb]->transy = sp[nb]->invdet *
		(-p->plany * sp[nb]->spx + p->planx * sp[nb]->spy);
	sp[nb]->spscreenx = (int)((map->res->x / 2)
		* (1 + sp[nb]->transx / (sp[nb]->transy)));
	sp[nb]->spheight = abs((int)(map->res->y / (sp[nb]->transy)));
	sp[nb]->starty = -sp[nb]->spheight / 2 + map->res->y / 2;
	sp[nb]->starty = (sp[nb]->starty < 0) ? 0 : sp[nb]->starty;
	sp[nb]->endy = sp[nb]->spheight / 2 + map->res->y / 2;
	sp[nb]->endy = (sp[nb]->endy >= map->res->y)
		? map->res->y - 1 : sp[nb]->endy;
	sp[nb]->spwidth = fabs((double)map->res->y / (sp[nb]->transy));
	sp[nb]->startx = -sp[nb]->spwidth / 2 + sp[nb]->spscreenx;
	sp[nb]->startx = (sp[nb]->startx < 0) ? 0 : sp[nb]->startx;
	sp[nb]->endx = sp[nb]->spwidth / 2 + sp[nb]->spscreenx;
	sp[nb]->endx = (sp[nb]->endx >= map->res->x)
		? map->res->x - 1 : sp[nb]->endx;
}

static void		ft_stripe_while(t_mapinfos *map,
	t_sprite **sp, int nb, int stripe)
{
	t_player	*p;
	int			y;
	int			color;
	int			d;

	p = map->p;
	sp[nb]->texx = (256 * (stripe - (-sp[nb]->spwidth / 2 + sp[nb]->spscreenx))
		* 64 / sp[nb]->spwidth) / 256;
	if (sp[nb]->transy > 0 && stripe > 0 && stripe < map->res->x
		&& sp[nb]->transy < p->zbuff[stripe])
	{
		y = sp[nb]->starty;
		while (y < sp[nb]->endy)
		{
			d = (y) * 256 - map->res->y * 128 + sp[nb]->spheight * 128;
			sp[nb]->texy = ((d * 64) / sp[nb]->spheight) / 256;
			color = map->text[4]->data[64 * sp[nb]->texy + sp[nb]->texx];
			if ((color & 0x00FFFFFF) != 0)
				map->mlx->img->data[(int)(y * map->res->x + stripe)] = color;
			y++;
		}
	}
}

void			ft_sprites_projections(t_mapinfos *map)
{
	t_player	*p;
	t_sprite	**sp;
	int			nb;
	int			stripe;

	p = map->p;
	sp = map->spinfos->sp;
	nb = -1;
	while (++nb < map->nbsp)
	{
		ft_width_height(map, map->spinfos->sp, map->p, nb);
		stripe = sp[nb]->startx;
		while (stripe++ < sp[nb]->endx)
			ft_stripe_while(map, sp, nb, stripe);
	}
}
