/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 18:32:20 by tidminta          #+#    #+#             */
/*   Updated: 2020/08/04 19:30:16 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void					ft_init_text(t_mapinfos *map)
{
	int			resx;
	int			resy;

	resx = map->res->x;
	resy = map->res->y;
	map->no->img_p = mlx_xpm_file_to_image(map->mlx->mlx_p, map->no->path,
		&resx, &resy);
	map->no->data = (int*)mlx_get_data_addr(map->no->img_p, &map->no->bpp,
		&map->no->s_l, &map->no->end);
}

static void				ft_drawtext2(t_mapinfos *map, t_mlx *mlx)
{
	int			y;
	int			color;
	t_player	*p;

	p = map->p;
	y = p->drawstart;
	while (y++ < p->drawend)
	{
		p->texy = (int)p->texpos & (TEXHEIGHT - 1);
		color = map->no->data[TEXHEIGHT * p->texy + p->texx];
		p->texpos += p->step;
		color = (p->side == 1) ? (color >> 1) & 8355711 : color;
		mlx->img->data[(int)(y * map->res->x + p->x)] = color;
	}
}

void					ft_drawtext(t_mapinfos *map, t_mlx *mlx)
{
	char		**map2d;
	t_player	*p;

	p = map->p;
	map2d = map->map_tab;
	if (p->side == 0)
		p->wallx = p->posy + p->perpwd * p->raydy;
	else
		p->wallx = p->posx + p->perpwd * p->raydx;
	p->wallx -= floor(p->wallx);
	p->texx = (int)(p->wallx * (double)TEXWIDTH);
	if (p->side == 0 && p->raydx > 0)
		p->texx = TEXWIDTH - p->texx - 1;
	if (p->side == 1 && p->raydy < 0)
		p->texx = TEXWIDTH - p->texx - 1;
	p->step = 1.0 * TEXHEIGHT / p->lineheight;
	p->texpos = (p->drawstart - map->res->y / 2 + p->lineheight / 2) * p->step;
	ft_drawtext2(map, mlx);
}
