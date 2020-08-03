/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 16:25:51 by tidminta          #+#    #+#             */
/*   Updated: 2020/08/03 18:03:07 by tidminta         ###   ########.fr       */
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
	int		fd;

	fd = open(av[1], O_RDONLY);
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

t_mapinfos	*ft_init_mapinfos(void)
{
	t_mapinfos	*map;

	map = (t_mapinfos*)malloc(sizeof(t_mapinfos));
	map->res = (t_res*)malloc(sizeof(t_res));
	map->no = (t_text*)malloc(sizeof(t_text));
	map->so = (t_text*)malloc(sizeof(t_text));
	map->we = (t_text*)malloc(sizeof(t_text));
	map->ea = (t_text*)malloc(sizeof(t_text));
	map->no->s_l = 0;
	map->no->bpp = 0;
	map->no->end = 0;
	map->res->x = 0;
	map->res->y = 0;
	map->map = ft_lstnew("");
	map->map_tab = NULL;
	map->sprite = NULL;
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
	return (mlx);
}

/*
**************************************
**			  PLAYER INIT			**
**				 DIRX/Y = 			**
**			FT_GETPLAYER POS		**
**************************************
*/

static	void		ft_init_player2(t_player **player_tmp)
{
	t_player	*player;

	player = *player_tmp;
	player->sidedy = 0;
	player->deltadx = 0;
	player->deltady = 0;
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
}

t_player			*ft_playerinit(void)
{
	t_player *player;

	if (!(player = (t_player*)malloc(sizeof(t_player))))
		return (NULL);
	player->posx = 0;
	player->posy = 0;
	player->dirx = -1;
	player->odirx = 0;
	player->diry = 0;
	player->planx = 0;
	player->oplanx = 0;
	player->plany = 0.66;
	player->time = 0;
	player->oldtime = 0;
	player->camx = 0;
	player->camy = 0;
	player->raydx = 0;
	player->raydy = 0;
	player->sidedx = 0;
	player->movespeed = 0.1;
	player->rot_s = 0.01;
	ft_init_player2(&player);
	return (player);
}
