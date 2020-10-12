/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 16:25:51 by tidminta          #+#    #+#             */
/*   Updated: 2020/10/12 19:09:37 by tidminta         ###   ########.fr       */
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
	int			fd;

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
	(*map)->win_h = (*map)->res->y;
	(*map)->win_w = (*map)->res->x;
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
	// system("leaks Cub3D");
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

t_player			*ft_playerinit(t_mapinfos *map)
{
	unsigned int	nb;
	t_player		*player;

	nb = map->res->x;
	if (!(player = (t_player*)malloc(sizeof(t_player))))
		return (NULL);
	ft_bzero(player, sizeof(t_player));
	player->zbuff = (double*)malloc(sizeof(double) * map->res->x);
	// ft_bzero(player->zbuff, sizeof(double*) * nb);
	player->movespeed = 0.2;
	player->rot_s = 0.1;
	map->p = player;
	ft_get_dir(map);
	return (player);
}
