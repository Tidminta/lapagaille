/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:10:15 by tidminta          #+#    #+#             */
/*   Updated: 2020/07/07 18:56:26 by tidminta         ###   ########.fr       */
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
** 								   **
*************************************
*/

int				ft_raycast(t_mapinfos **map_tmp, t_mlx	**mlx)
{
	int			x;
	int			y;
	double		tern_tmp;
	char		**map2d;
	t_mapinfos	*map;
	t_player	*player;

	map = *map_tmp;
	map2d = map->map_tab;
	x = 0;
	y = 0;
	player = ft_playerinit();
	if (!player)
		return (-1);
	map->mlx = *mlx;
	player->posx = map->start_x;
	player->posy = map->start_y;
	player->dirx = -1;
	player->diry = 0;
	player->planx = 0;
	player->plany = 0.66;
	player->x = 0;
	while ((size_t)player->x < map->resolution->res_x)
	{
		//calcul de la position du vecteur et sa direction
		player->camx = (2 * player->x / ((double)map->resolution->res_x - 1));
		player->raydx = player->dirx + player->planx * player->camx;
		player->raydy = player->diry + player->plany * player->camx;
		//length of ray from one x or y-side to next x or y-side
		player->mapx = (int)player->posx;
		player->mapy = (int)player->posy;
		player->deltadx = fabs(1 / player->raydx);
		player->deltady = fabs(1 / player->raydy);
		// Alternative code for deltaDist in case division through zero is not supported
		tern_tmp = (player->raydx == 0) ? 1 : fabs(1 / player->raydx);
		player->deltadx = (player->raydy == 0) ? 0 : tern_tmp;
		tern_tmp = (player->raydy == 0) ? 1 : fabs(1 / player->raydy);
		player->deltady = (player->raydx == 0) ? 1 : tern_tmp;
		//calculate step and initial sideDist
		if (player->raydx < 0)
		{
			player->stepx = -1;
			player->sidedx = (player->posx - player->mapx) * player->deltadx;
		}
		else
		{
			player->stepx = 1;
			player->sidedx = (player->mapx + 1.0 - player->posx) * player->deltadx;
		}
		if (player->raydy < 0)
		{
			player->stepy = -1;
			player->sidedy = (player->posy - player->mapy) * player->deltady;
		}
		else
		{
			player->stepy = 1;
			player->sidedy = (player->mapy + 1.0 - player->posy) * player->deltady;
		}
		while (!player->hit)
		{
			if (player->sidedx < player->sidedy)
			{
				player->sidedx += player->deltadx;
				player->mapx += player->stepx;
				player->side = 0;
			}
			else
			{
				player->sidedy += player->deltady;
				player->mapy += player->stepy;
				player->side = 1;
			}
			if (map2d[player->mapy][player->mapx] == '1')
			{
				printf("[mapy = %d][mapx = %d]\n", player->mapy, player->mapx);
				player->hit = 1;
			}
		}
		if (player->side == 0)
			player->perpwd = (player->mapx - player->posx + (1 - player->stepx) / 2) / player->raydx;
		else
			player->perpwd = (player->mapy - player->posy + (1 - player->stepy) / 2) / player->raydy;
		player->lineheight = ((int)map->win_h / player->perpwd);
		player->drawstart = -player->lineheight / 2 + map->win_h / 2;
		player->drawstart = (player->drawstart < 0) ? 0 : player->drawstart;
		player->drawend = player->lineheight / 2 + map->win_h / 2;
		if (player->drawend >= (int)map->win_h)
			player->drawend = map->win_h - 1;
		// player->drawend = (player->drawend >= (int)map->win_h) ? (map->win_h - 1): player->drawend;
		// ft_print_playerinfos(player);
		player->x += 1;
		// player->mapx += player->stepx;
		// player->mapy += player->stepy;
	}
	mlx_loop(map->mlx->mlx_ptr);
	mlx_put_image_to_window(map->mlx->mlx_ptr, map->mlx->win, map->mlx->img->img_ptr, 0, 0);
	return (1);
}
