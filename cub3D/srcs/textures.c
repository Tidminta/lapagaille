/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 18:32:20 by tidminta          #+#    #+#             */
/*   Updated: 2020/09/07 19:10:15 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int						ft_get_index(t_player *p)
{
	/** NO **/
	if ((-1 >= p->diry <= 0) && (p->planx == 0))
		return (1);
	/** SO **/
	else if ((-1 >= p->dirx <= 0) && (-1 >= p->diry <= 0) &&
		(-0.66 >= p->planx <= 0) && (0 >= p->plany <= 0.66))
		return (2);
	/** EA **/
	// else if ((-1 >= p->dirx <= 0) && (-1 >= p->diry <= 0) &&
	// 	(-0.66 >= p->planx <= 0) && (0 >= p->plany <= 0.66))
	// 	return (3);
	/** WE **/
	else
		return (0);
}

void					ft_init_text(t_mapinfos *map)
{
	int			resx;
	int			resy;

	resx = map->res->x;
	resy = map->res->y;
	map->text[0]->img_p = mlx_xpm_file_to_image(map->mlx->mlx_p,
		map->text[0]->path, &resx, &resy);
	map->text[0]->data = (int*)mlx_get_data_addr(map->text[0]->img_p,
		&map->text[0]->bpp, &map->text[0]->s_l, &map->text[0]->end);
	map->text[1]->img_p = mlx_xpm_file_to_image(map->mlx->mlx_p,
		map->text[1]->path, &resx, &resy);
	map->text[1]->data = (int*)mlx_get_data_addr(map->text[1]->img_p,
		&map->text[1]->bpp, &map->text[1]->s_l, &map->text[1]->end);
	map->text[2]->img_p = mlx_xpm_file_to_image(map->mlx->mlx_p,
		map->text[2]->path, &resx, &resy);
	map->text[2]->data = (int*)mlx_get_data_addr(map->text[2]->img_p,
		&map->text[2]->bpp, &map->text[2]->s_l, &map->text[2]->end);
	map->text[3]->img_p = mlx_xpm_file_to_image(map->mlx->mlx_p,
		map->text[3]->path, &resx, &resy);
	map->text[3]->data = (int*)mlx_get_data_addr(map->text[3]->img_p,
		&map->text[3]->bpp, &map->text[3]->s_l, &map->text[3]->end);
}

static void				ft_drawtext2(t_mapinfos *map, t_mlx *mlx)
{
	int			y;
	int			color;
	int			nb;
	t_player	*p;

	p = map->p;
	y = p->drawstart;
	// nb = 3;
	while (y++ < p->drawend)
	{
		nb = ft_get_index(map->p);
		p->texy = (int)p->texpos & (TEXHEIGHT - 1);
		color = map->text[nb]->data[TEXHEIGHT * p->texy + p->texx];
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
