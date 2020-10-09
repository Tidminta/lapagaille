/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 16:25:51 by tidminta          #+#    #+#             */
/*   Updated: 2020/10/09 17:34:14 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/*
**************************************
**			MAP PARSING				**
**			MLX START				**
**************************************
*/

int					ft_parse_open(char **av, t_mapinfos **map, t_list **list,
					t_list **garb)
{
	t_mapinfos	*m;
	int			fd;

	m = *map;
	fd = 0;
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (-1);
	if ((fd = ft_parseinfos(list, map, fd, *garb)) <= 0)
		return (fd);
	if (!((*(map))->p = ft_playerinit(*map)))
		return (-3);
	if (!((*(map))->mlx = ft_start_mlx(*map)))
		return (-3);
	if ((ft_sprite_cpt(*map)) < 0)
		return (-3);
	if (!(ft_sprites_init(*map)))
		return (-3);
	return (fd);
}

t_mapinfos			*ft_init_mapinfos(int i, t_list *garbage)
{
	t_mapinfos		*map;

	map = (t_mapinfos *)ft_garbage_collector(&garbage, sizeof(t_mapinfos));
	map->res = (t_res*)ft_garbage_collector(&garbage, sizeof(t_res));
	map->spinfos = (t_infosprt*)ft_garbage_collector(&garbage,sizeof(t_infosprt));
	map->text = (t_text**)ft_garbage_collector(&garbage, sizeof(t_text*) * 5);
	while (++i < 5)
		map->text[i] = (t_text*)ft_garbage_collector(&garbage, sizeof(t_text));
	if (!(map->map = ft_lstnew("")))
		return (NULL);
	map->map_tab = NULL;
	map->nbsp = 0;
	map->res->x = 0;
	map->res->y = 0;
	map->line_max = 0;
	map->col_max = 0;
	map->start_x = 0;
	map->start_y = 0;
	map->garbage = garbage;
	return (map);
}

t_mlx				*ft_start_mlx(t_mapinfos *map)
{
	int		i;
	t_mlx	*mlx;

	i = -1;
	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		return (NULL);
	if (!(mlx->img = (t_img*)malloc(sizeof(t_img))))
	{
		free(mlx);
		return (NULL);
	}
	if (!(mlx->mlx_p = mlx_init()))
		return (NULL);
	mlx->win = mlx_new_window(mlx->mlx_p, map->res->x, map->res->y, "Cub3D");
	if (!mlx->win)
		return (NULL);
	// map->mlx = mlx;
	return (mlx);
}

/*
**************************************
**			  PLAYER INIT			**
**				 DIRX/Y = 			**
**			FT_GETPLAYER POS		**
**************************************
*/

static	void		ft_init_player2(t_player **player_tmp, t_mapinfos *map)
{
	t_player	*player;

	player = *player_tmp;
	player->perpwd = 0;
	player->mapx = 0;
	player->mapy = 0;
	player->stepx = 0;
	player->stepy = 0;
	player->x = 0;
	player->hit = 0;
	player->side = 0;
	player->lineheight = 0;
	player->drawstart = 0;
	player->drawend = 0;
	player->m_up = 0;
	player->m_down = 0;
	player->m_right = 0;
	player->m_left = 0;
	map->p = player;
	ft_get_dir(map);
}

t_player			*ft_playerinit(t_mapinfos *map)
{
	t_player *player;

	if (!(player = (t_player*)malloc(sizeof(t_player))))
		return (NULL);
	// ft_bzero(player, sizeof(t_player));
	player->zbuff = (double*)malloc(sizeof(double) * map->res->x);
	// ft_bzero(player->zbuff, sizeof(player->zbuff));
	player->dirx = 0;
	player->diry = 0;
	player->planx = 0;
	player->plany = 0;
	player->posx = 0;
	player->posy = 0;
	player->odirx = 0;
	player->oplanx = 0.0;
	player->time = 0;
	player->oldtime = 0;
	player->camx = 0;
	player->raydx = 0;
	player->raydy = 0;
	player->sidedx = 0;
	player->movespeed = 0.2;
	player->rot_s = 0.01;
	player->sidedy = 0;
	player->deltadx = 0;
	player->deltady = 0;
	ft_init_player2(&player, map);
	return (player);
}
