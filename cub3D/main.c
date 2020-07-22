/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:42:32 by tidminta          #+#    #+#             */
/*   Updated: 2020/07/22 02:09:01 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub.h"

/*
**************************************
**			MAP PARSING				**
**			MLX START				**
**************************************
*/

static int			ft_parse_open(char **av, t_mapinfos **map, t_list **list)
{
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nMap file open failed\n");
		return (fd);
	}
	if ((ft_parseinfos(list, map, fd)) <= 0)
	{
		printf("Error\nMap parsing failed\n");
		return (-1);
	}
	return (fd);
}

static t_mlx		*ft_start_mlx(t_mapinfos *map, t_player *p)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	mlx->img = (t_img*)malloc(sizeof(t_img));
	mlx->mlx_p = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_p, map->res->x, map->res->y, "Cub3D");
	// mlx->img->img_p = mlx_new_image(mlx->mlx_p, map->res->x, map->res->y);
	// mlx->img->data = (int *)mlx_get_data_addr(mlx->img->img_p, &mlx->img->bpp,
	// 	&mlx->img->size_l, &mlx->img->endian);
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
}

static t_player		*ft_playerinit(void)
{
	t_player *player;

	if (!(player = (t_player*)malloc(sizeof(t_player))))
		return (player);
	player->posx = 0;
	player->posy = 0;
	player->dirx = 0;
	player->diry = 0;
	player->planx = 0;
	player->plany = 0.66;
	player->time = 0;
	player->oldtime = 0;
	player->camx = 0;
	player->camy = 0;
	player->raydx = 0;
	player->raydy = 0;
	player->sidedx = 0;
	player->movespeed = 5.0;
	player->rotspeed = 3.0;
	ft_init_player2(&player);
	return (player);
}

static int				ft_game_loop(t_mapinfos **map_tmp)
{
	t_mlx		*mlx;
	t_mapinfos *map;

	map = *map_tmp;
	mlx = map->mlx;
	mlx->img->img_p = mlx_new_image(map->mlx->mlx_p, map->res->x, map->res->y);
	mlx->img->data = (int *)mlx_get_data_addr(map->mlx->img->img_p, &map->mlx->img->bpp,
			&map->mlx->img->size_l, &map->mlx->img->endian);
	ft_raycast(&map, mlx, map->p);
	mlx_clear_window(map->mlx->mlx_p, map->mlx->win);
	mlx_put_image_to_window(map->mlx->mlx_p, map->mlx->win, map->mlx->img->img_p, 0, 0);
	return (0);
}

/*
**************************************
**			  	MAIN              	**
**     PENSER A TOUT FREE         	**
** 		-g3 -fsanitize=address      **
** mlx_hoock keypress/release	    **
**************************************
*/

int					main(int ac, char **av)
{
	t_list		*list;
	t_mapinfos	*map;
	t_mlx		*mlx;
	t_player	*p;
	int			fd;

	if (ac == 2)
	{
		list = NULL;
		mlx = NULL;
		if ((fd = ft_parse_open(av, &map, &list)) < 0)
			return (0);
		close(fd);
		p = ft_playerinit();
		mlx = ft_start_mlx(map, p);
		// ft_game_loop(&map);
		// mlx_hook(mlx->win, KEYPRESS, KEYPRESSMASK, &ft_dealkey, &map);
		mlx_key_hook(mlx->win, &ft_dealkey, &map);
		mlx_loop_hook(mlx->mlx_p, &ft_game_loop, &map);
		mlx_loop(mlx->mlx_p);
		system("leaks Cub3D");
		return (0);
	}
	printf("Error\nInvalide number of arguments!\n");
	return (0);
}
