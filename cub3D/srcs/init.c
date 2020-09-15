/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 16:25:51 by tidminta          #+#    #+#             */
/*   Updated: 2020/09/14 16:31:21 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/*
**************************************
**			MAP PARSING				**
**			MLX START				**
**************************************
*/

int					ft_parse_open(char **av, t_mapinfos **map, t_list **list)
{
	int			fd;
	int			ret;
	// t_mapinfos	*tmp;

	fd = open(av[1], O_RDONLY);
	ret = -1;
	if (fd < 0)
	{
		printf("Error\nMap file open failed\n");
		return (-1);
	}
	if ((ft_parseinfos(list, map, fd)) <= 0)
	{
		printf("Error\nMap parsing failed\n");
		return (-1);
	}
	return (fd);
}

t_mapinfos			*ft_init_mapinfos(void)
{
	t_mapinfos	*map;

	map = (t_mapinfos*)malloc(sizeof(t_mapinfos));
	map->res = (t_res*)malloc(sizeof(t_res));
	map->text = (t_text**)malloc(sizeof(t_text*) * 5);
	map->text[0] = (t_text*)malloc(sizeof(t_text));
	map->text[1] = (t_text*)malloc(sizeof(t_text));
	map->text[2] = (t_text*)malloc(sizeof(t_text));
	map->text[3] = (t_text*)malloc(sizeof(t_text));
	map->text[4] = (t_text*)malloc(sizeof(t_text));
	map->map = ft_lstnew("");
	map->map_tab = NULL;
	map->nbspt = 0;
	map->res->x = 0;
	map->res->y = 0;
	map->line_max = 0;
	map->col_max = 0;
	map->start_x = 0;
	map->start_y = 0;
	return (map);
}

t_mlx				*ft_start_mlx(t_mapinfos *map, t_player *p)
{
	t_mlx	*mlx;

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
	map->p = p;
	map->mlx = mlx;
	ft_init_text(map);
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
	player->dirx = 0;
	player->diry = 0;
	player->planx = 0;
	player->planx = 0;
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
	player->movespeed = 0.1;
	player->rot_s = 0.01;
	player->sidedy = 0;
	player->deltadx = 0;
	player->deltady = 0;
	ft_init_player2(&player, map);
	return (player);
}
