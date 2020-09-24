/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:16:32 by tidminta          #+#    #+#             */
/*   Updated: 2020/09/24 16:45:59 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void			ft_sprites_projections(t_mapinfos *map)
{
	t_player	*p;
	t_sprite	**sp;
	int			nb;
	int			color;
	int			y;
	int			stripe;

	p = map->p;
	sp = map->spinfos->sp;
	nb = -1;
	while (++nb < map->nbsp)
	{
		sp[nb]->spx = sp[nb]->x - p->posx;
		sp[nb]->spy = sp[nb]->y - p->posy;
		sp[nb]->invdet = 1.0 / (p->planx * p->diry - p->dirx * p->plany);
		sp[nb]->transx = sp[nb]->invdet * (p->diry * sp[nb]->spx - p->dirx * sp[nb]->spx);
		sp[nb]->transy = sp[nb]->invdet * (-p->plany * sp[nb]->spx + p->planx * sp[nb]->spy);
		sp[nb]->spscreenx = (int)((map->res->x / 2)
			* (1 + sp[nb]->transx / sp[nb]->transy));
//calculate height of the sprite on screen
		sp[nb]->spheight = abs((int)(map->res->y / sp[nb]->transy));
		sp[nb]->starty = -sp[nb]->spheight / 2 + map->res->y / 2;
		sp[nb]->starty = (sp[nb]->starty < 0) ? 0 : sp[nb]->starty;
		sp[nb]->endy = sp[nb]->spheight / 2 + map->res->y / 2;
		sp[nb]->endy = (sp[nb]->endy >= map->res->y) ? map->res->y - 1 : sp[nb]->endy;
		// ft_sprites_projection2(map);
//calculate width of the sprite
		sp[nb]->spwidth = abs((map->res->y / (int)sp[nb]->transy));
		sp[nb]->startx = -sp[nb]->spwidth / 2 + sp[nb]->spscreenx;
		sp[nb]->startx = (sp[nb]->startx < 0) ? 0 : sp[nb]->startx;
		sp[nb]->endx = sp[nb]->spwidth / 2 + sp[nb]->spscreenx;
		sp[nb]->endx = (sp[nb]->endx >= map->res->x) ? map->res->x - 1 : sp[nb]->endx;
//loop through every vertical stripe of the sprite on screen
		stripe = sp[nb]->startx;
		// ft_print_spriteinfos(map->spinfos);
		while (stripe < sp[nb]->endx)
		{
			sp[nb]->texx = (int)(256 * (stripe - (-sp[nb]->spwidth / 2 + sp[nb]->spscreenx)) * 512 / sp[nb]->spwidth) / 256;
			if (sp[nb]->transy > 0 && stripe > 0 && stripe < map->res->x && sp[nb]->transy < p->zbuff[stripe])
			{
				y = sp[nb]->starty;
				while (y < sp[nb]->endy)
				{
					// int d = (y) * 256 - map->res->y * 128 + sp[nb]->spheight * 128;
					sp[nb]->texy = ((((y) * 256 - map->res->y * 128 + sp[nb]->spheight * 128) * 512) / sp[nb]->spheight) / 256;
					color = map->text[4]->data[512 * sp[nb]->texy * sp[nb]->texx];
					// [4][(int)(s->tex_y * SPRITE + s->tex_x)];
					// if ((color & 0x00FFFFFF) != 0)
					// 	map->mlx->img->data[(int)(y * sp->stripe)] = color;
						map->mlx->img->data[(int)(y * map->res->x + sp[nb]->startx)] = color;
					y++;
				}
			}
			stripe++;
		}
	}
} 

				// if (cub->img->data_textures[4][(int)(s->tex_y * SPRITE + s->tex_x)] != cub->img->data_textures[4][0])
					// cub->img->img_buf[(s->y_start + cub->sprites->check_y) * cub->map->res_x + (s->x_start + cub->sprites->check_x)] = cub->img->data_textures[4][(int)(s->tex_y * SPRITE + s->tex_x)];