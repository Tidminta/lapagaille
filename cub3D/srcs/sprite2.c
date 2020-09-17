/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:16:32 by tidminta          #+#    #+#             */
/*   Updated: 2020/09/17 19:38:13 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void			ft_sprites_projections(t_mapinfos *map)
{
	t_player	*p;
	t_infosprt	*sp;
	int			nb;
	int			color;
	int			y;

	p = map->p;
	sp = map->spinfos;
	nb = -1;
	while (++nb < map->nbsp)
	{
		sp->spx = sp->sp[nb]->x - p->posx;
		sp->spy = sp->sp[nb]->y - p->posy;
		sp->invdet = 1.0 / (p->planx * p->diry - p->dirx * p->plany);
		sp->transx = sp->invdet * (p->diry * sp->spx - p->dirx * sp->spx);
		sp->transy = sp->invdet * (-p->plany * sp->spx + p->planx * sp->spy);
		sp->spscreenx = (int)((map->res->x / 2)
			* (1 + sp->transx / sp->transy));
//calculate height of the sprite on screen
		sp->spheight = abs((int)(map->res->y / sp->transy));
		sp->starty = -sp->spheight / 2 + map->res->y / 2;
		sp->starty = (sp->starty < 0) ? 0 : sp->starty;
		sp->endy = sp->spheight / 2 + map->res->y / 2;
		sp->endy = (sp->endy >= map->res->y) ? map->res->y - 1 : sp->endy;
		// ft_sprites_projection2(map);
//calculate width of the sprite
		sp->spwidth = abs((map->res->y / (int)sp->transy));
		sp->startx = -sp->spwidth / 2 + sp->spscreenx;
		sp->startx = (sp->startx < 0) ? 0 : sp->startx;
		sp->endx = sp->spwidth / 2 + sp->spscreenx;
		sp->endx = (sp->endx >= map->res->x) ? map->res->x - 1 : sp->endx;
//loop through every vertical stripe of the sprite on screen
		sp->stripe = sp->startx;
		ft_print_spriteinfos(map->spinfos);
		while (sp->stripe < sp->endx)
		{
			sp->texx = (int)(256 * (sp->stripe - (-sp->spwidth / 2 + sp->spscreenx)) * TEXWIDTH / sp->spwidth) / 256;
			if (sp->transy > 0 && sp->stripe > 0 && sp->stripe < map->res->x && sp->transy < p->zbuff[sp->stripe])
			{
				y = sp->starty;
				while (y++ < sp->endy)
				{
					int d = (y) * 256 - map->res->y * 128 + sp->spheight * 128;
					sp->texy = ((d * TEXHEIGHT) / sp->spheight) / 256;
					color = map->text[4]->data[TEXWIDTH * sp->texy * sp->texx];
					// if ((color & 0x00FFFFFF) != 0)
					// 	map->mlx->img->data[(int)(y * sp->stripe)] = color;
				}
			}
		}
	}
}
