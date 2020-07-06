/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:21:41 by tidminta          #+#    #+#             */
/*   Updated: 2020/07/06 15:46:25 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int			ft_parse_open(char **av, t_mapinfos **map, t_list **list)
{
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nMap file open failed\n");
		return (fd);
	}
	if ((ft_parseinfos(list, map, fd)) <= 0)
	{
		ft_printf("Error\nMap parsing failed\n");
		return (-1);
	}
	// ft_print_mapinfos(*map);
	return (fd);
}

t_mlx		*ft_start_mlx(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	mlx->img = (t_img*)malloc(sizeof(t_img));
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "mlx42");
	mlx->img->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->img->data = (int *)mlx_get_data_addr(mlx->img->img_ptr, &mlx->img->bpp,
			&mlx->img->size_l, &mlx->img->endian);
	return (mlx);
}

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
}

t_player	*ft_playerinit(void)
{
	t_player *player;

	if (!(player = (t_player*)malloc(sizeof(t_player))))
		return (player);
	player->posx = 0;
	player->posy = 0;
	player->dirx = 0;
	player->diry = 0;
	player->planx = 0;
	player->plany = 0;
	player->time = 0;
	player->oldtime = 0;
	player->camx = 0;
	player->camy = 0;
	player->raydx = 0;
	player->raydy = 0;
	player->sidedx = 0;
	ft_init_player2(&player);
	// ft_print_playerinfos(player);
	return (player);
}
