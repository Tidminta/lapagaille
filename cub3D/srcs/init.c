/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 16:25:51 by tidminta          #+#    #+#             */
/*   Updated: 2020/10/28 15:07:53 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int					ft_parse_open(char **av, t_mapinfos **map, t_list **list,
					t_list **garb)
{
	int			fd;

	fd = 0;
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_error(NULL, "Error\nMap opening failled\n", -1, NULL);
	if (ft_strncmp(".cub", ft_strchr(av[1], '.'), 4))
		ft_error(&(*map)->garbage, "Error\nBad file extention!\n", 0, NULL);
	if (ft_parseinfos(list, map, fd, *garb) < 0)
	{
		close(fd);
		ft_error(&(*map)->garbage, "Error\nMapinfos init failed\n", 0, NULL);
	}
	if (!(ft_double_path(*map)))
		ft_error(&(*map)->garbage, "Error\nBad or Same Path 2 time\n", 0, *map);
	if (!((*(map))->p = ft_playerinit(*map)))
		ft_error(&(*map)->garbage, "Error\nPlayer init failled\n", 0, (*map));
	if (!((*(map))->mlx = ft_start_mlx(*map)))
		ft_error(&(*map)->garbage, "Error\nMLX failled.\n", 0, (*map));
	if ((ft_sprite_cpt(*map)) < 0)
		ft_error(&(*map)->garbage,
			"Error\nMalloc failled somewhere\n", 0, (*map));
	ft_sprites_init(*map);
	(*map)->win_h = (*map)->res->y;
	(*map)->win_w = (*map)->res->x;
	return (fd);
}

t_mapinfos			*ft_init_mapinfos(int i, t_list *garbage)
{
	t_mapinfos		*map;

	map = (t_mapinfos *)ft_garbage_collector(&garbage,
	NULL, sizeof(t_mapinfos), 0);
	map->res = (t_res*)ft_garbage_collector(&garbage, map, sizeof(t_res), 0);
	map->spinfos = (t_infosprt*)ft_garbage_collector(&garbage, NULL,
		sizeof(t_infosprt), 0);
	map->text = (t_text**)ft_garbage_collector(&garbage, NULL,
		sizeof(t_text*) * 5, 0);
	while (++i < 5)
		map->text[i] = (t_text*)ft_garbage_collector(&garbage, NULL,
			sizeof(t_text), 0);
	if (!(map->map = ft_lstnew(ft_strdup("\0"))))
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
	map->screenshoot = 0;
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
	return (mlx);
}

t_player			*ft_playerinit(t_mapinfos *map)
{
	int				nb;
	t_player		*player;

	map->res->x = (map->res->x < 0) ? 0 : map->res->x;
	nb = map->res->x;
	player = (t_player*)ft_garbage_collector(&map->garbage, map,
		sizeof(t_player), map->fd);
	ft_bzero(player, sizeof(t_player));
	player->zbuff = (double*)ft_garbage_collector(&map->garbage, map,
		sizeof(double) * map->res->x, map->fd);
	ft_bzero(player->zbuff, sizeof(double*) * (size_t)nb);
	player->movespeed = 0.2;
	player->rot_s = 0.1;
	map->p = player;
	ft_get_dir(map);
	return (player);
}
