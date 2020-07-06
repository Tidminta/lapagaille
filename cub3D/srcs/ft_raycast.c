/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:10:15 by tidminta          #+#    #+#             */
/*   Updated: 2020/07/06 16:13:41 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/*
*************************************
**			  FCTS                 **
**	(DIRX/Y)?? |                   **
**	DO FONCTION QUI SET DIRX/Y     **
**	EN FONCTION DE N,S,E OU W      **
**	RECAP FINIR DDA				   **
**	14443600					   **	
*************************************
*/

static	void		ft_set_sidedist(t_mapinfos **map_tmp, t_player **player_tmp)
{
	t_mapinfos	*map;
	t_player	*player;

	map = *map_tmp;
	player = *player_tmp;
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
}

static	void		ft_ray_pos_dir(t_mapinfos **map_tmp, t_player **player_tmp)
{
	t_mapinfos	*map;
	t_player	*player;
	double		tern_tmp;

	map = *map_tmp;
	player = *player_tmp;
	player->camx = (2 * player->x / ((double)map->win_w) - 1);
	player->raydx = player->dirx + (player->planx * player->camx);
	player->raydy = player->diry + (player->plany * player->camx);
	player->mapx = (int)player->posx;
	player->mapy = (int)player->posy;
	player->deltadx = fabs(1 / player->raydx);
	player->deltady = fabs(1 / player->raydy);
	tern_tmp = (player->raydx == 0) ? 1 : fabs(1 / player->raydx);
	player->deltadx = (player->raydy == 0) ? 0 : tern_tmp;
	tern_tmp = (player->raydy == 0) ? 1 : fabs(1 / player->raydy);
	player->deltady = (player->raydx == 0) ? 1 : tern_tmp;
}

static	void		ft_ray_dda(t_mapinfos **map_tmp, t_player **player_tmp)
{
	t_mapinfos	*map;
	t_player	*player;
	char		**map2d;

	map = *map_tmp;
	player = *player_tmp;
	map2d = map->map_tab;
	player->hit = 0;
	player->side = 0;
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
			player->hit = 1;
		}
	}
	if (player->side == 0)
	{
		player->perpwd = (((player->mapx - player->posx +
			(1 - player->stepx)) / 2) / player->raydx);
	}
	else
		player->perpwd = (((player->mapy - player->posy +
			(1 - player->stepy)) / 2) / player->raydy);
}

static	void			ft_get_draw_height(t_mapinfos **map_tmp, t_player **player_tmp)
{
	t_mapinfos		*map;
	t_player		*player;

	map = *map_tmp;
	player = *player_tmp;
	player->lineheight = ((int)map->win_h / player->perpwd);
	player->drawstart = (- player->lineheight / 2) + (map->win_h / 2);
	player->drawstart = (player->drawstart < 0) ? 0 : player->drawstart;
	player->drawend = (player->lineheight / 2) + (map->win_h / 2);
	player->drawend = (player->drawend >= (int)map->win_h) ? (map->win_h - 1): player->drawend;
	ft_draw_wall(map, player);
}

int				ft_raycast(t_mapinfos **map, t_mlx	**mlx)
{
	t_mapinfos	*tmp;
	t_player	*player;

	tmp = *map;
	player = ft_playerinit();
	tmp->mlx = *mlx;
	if (!player)
		return (-1);
	player->posx = tmp->start_x;
	player->posy = tmp->start_y;
	player->dirx = -1;
	player->diry = 0;
	player->planx = 0;
	player->plany = 0.66;
	player->x = 0;
	while ((size_t)player->x < tmp->win_w)
	{
		ft_ray_pos_dir(&tmp, &player);
		ft_set_sidedist(&tmp, &player);
		ft_ray_dda(&tmp, &player);
		ft_get_draw_height(&tmp, &player);
		ft_print_playerinfos(player);
		player->x += 1;
	}
	mlx_put_image_to_window(tmp->mlx->mlx_ptr, tmp->mlx->win, tmp->mlx->img->img_ptr, 0, 0);
	return (1);
}
