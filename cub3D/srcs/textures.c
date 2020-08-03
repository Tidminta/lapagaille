/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 18:32:20 by tidminta          #+#    #+#             */
/*   Updated: 2020/08/03 19:51:55 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void				ft_init_text(t_mapinfos **map_tmp)
{
	t_mapinfos	*map;
	int			resx;
	int			resy;

	map = *map_tmp;
	resx = map->res->x;
	resy = map->res->y;
	map->no->img_p = mlx_xpm_file_to_image(map->mlx->mlx_p, map->no->path,
		&resx, &resy);
	map->no->data = (int*)mlx_get_data_addr(map->no->img_p, &map->no->bpp,
		&map->no->s_l, &map->no->end);
}

void				ft_text1(t_mapinfos **map_tmp, t_mlx *mlx)
{
	char		**map2d;
	t_mapinfos	*map;
	t_player	*p;
	int			color;
	int			y;

	map = *map_tmp;
	p = map->p;
	map2d = map->map_tab;
	// calculate value of wallx
	p->wallx = map2d[p->mapx][p->mapy];
	if (p->side == 0)
		p->wallx = p->posy + p->perpwd * p->raydy;
	else
		p->wallx = p->posx + p->perpwd * p->raydx;
	// x coordinate on the texture
	p->texx = (int)(p->wallx * (double)TEXWIDTH);
	if (p->side == 0 && p->raydx > 0)
		p->texx = TEXWIDTH - p->texx;
	if (p->side == 1 && p->raydy < 0)
		p->texx = TEXWIDTH - p->texx;
	// How much to increase the texture coordinate per screen pixel
	p->step = 1.0 * TEXHEIGHT / p->lineheight;
	// Starting texture coordinate
	p->texpos = (p->drawstart - map->res->y / 2 + p->lineheight / 2) * p->step;
	y = p->drawstart;
	while (y++ < p->drawend)
	{
		p->texy = (int)p->texpos & (TEXHEIGHT - 1);
		p->texpos += p->step;
		color = map->no->data[TEXHEIGHT * p->texy + p->texx];
		mlx->img->data[(int)(y * map->res->x + p->x)] = color;
		printf("");
	}
}
