/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:42:32 by tidminta          #+#    #+#             */
/*   Updated: 2020/10/27 19:33:51 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int					ft_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static int			ft_game_loop(t_mapinfos *map)
{
	int			ret;
	t_mlx		*mlx;

	mlx = map->mlx;
	if (!(mlx->img->img_p = mlx_new_image(map->mlx->mlx_p,
		map->res->x, map->res->y)))
		ft_error(&map->garbage, "Error\nMalloc error\n", 0, map);
	if (!(mlx->img->data = (int *)mlx_get_data_addr(mlx->img->img_p,
		&mlx->img->bpp, &mlx->img->size_l, &mlx->img->endian)))
		ft_error(&map->garbage, "Error\nMalloc error\n", 0, map);
	if ((ret = ft_init_text(map)) < 0)
		ft_error(&map->garbage, "Error\nBad textures path!\n", 0, map);
	ft_setmove(map);
	ft_raycast(map, mlx, map->p);
	ft_spritecast(map);
	ft_free_text(map);
	if (map->screenshoot)
	{
		ft_screen_shoot(map);
		mlx_destroy_image(mlx->mlx_p, mlx->img->img_p);
	}
	mlx_clear_window(map->mlx->mlx_p, map->mlx->win);
	mlx_put_image_to_window(mlx->mlx_p, mlx->win, mlx->img->img_p, 0, 0);
	mlx_destroy_image(mlx->mlx_p, mlx->img->img_p);
	return (0);
}

static int			ft_cross(void)
{
	exit(0);
}

int					main(int ac, char **av)
{
	t_list		*list;
	t_list		*garbage;
	t_mapinfos	*map;

	if (ac >= 2)
	{
		list = NULL;
		if (!(garbage = ft_lstnew(ft_strdup("0"))))
			ft_error(&garbage, "Error\nIt's may be a malloc error.\n", 1, NULL);
		ft_parse_open(av, &map, &list, &garbage);
		if (!(ft_check_save(map, ac, av)))
			ft_error(&garbage, "Error\nBad argument for save option!", 0, map);
		mlx_hook(map->mlx->win, DESTROY, 1L << 17, ft_cross, &map);
		mlx_hook(map->mlx->win, KEYPRESS, 1L << 0, ft_keypress, &map);
		mlx_hook(map->mlx->win, KEYRELEASE, 1L << 1, ft_keyrelease, &map);
		mlx_loop_hook(map->mlx->mlx_p, &ft_game_loop, map);
		mlx_loop(map->mlx->mlx_p);
		ft_error(&garbage, NULL, 0, map);
	}
	ft_putstr_fd("Error\nInvalide number of arguments!\n", 1);
	return (0);
}
