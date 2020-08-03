/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:42:32 by tidminta          #+#    #+#             */
/*   Updated: 2020/08/03 20:02:21 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int					ft_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static int			ft_game_loop(t_mapinfos **map_tmp)
{
	t_mlx		*mlx;
	t_mapinfos	*map;

	map = *map_tmp;
	mlx = map->mlx;
	mlx->img->img_p = mlx_new_image(map->mlx->mlx_p, map->res->x, map->res->y);
	mlx->img->data = (int *)mlx_get_data_addr(mlx->img->img_p, &mlx->img->bpp,
			&mlx->img->size_l, &mlx->img->endian);
	ft_init_text(map_tmp);
	ft_setmove(map_tmp);
	ft_raycast(&map, mlx, map->p);
	mlx_clear_window(map->mlx->mlx_p, map->mlx->win);
	mlx_put_image_to_window(mlx->mlx_p, mlx->win, mlx->img->img_p, 0, 0);
	mlx_destroy_image(mlx->mlx_p, mlx->img->img_p);
	mlx_destroy_image(mlx->mlx_p, map->no->img_p);
	return (0);
}

/*
**************************************
**			  	MAIN              	**
**     	PENSER A TOUT FREE         	**
** 		-g3 -fsanitize=address      **
**		!factoriser params fcts!  	**
**************************************
*/

//recap : fix ft_text1 voir capture d'ecran

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
		if (!(p = ft_playerinit()))
			return (0);
		if (!(mlx = ft_start_mlx(map, p)))
			return (0);
		mlx_hook(mlx->win, KEYPRESS, KEYPRESSMASK, ft_keypress, &map);
		mlx_hook(mlx->win, KEYRELEASE, KEYRELEASEMASK, ft_keyrelease, &map);
		mlx_loop_hook(mlx->mlx_p, &ft_game_loop, &map);
		mlx_loop(mlx->mlx_p);
		return (0);
	}
	printf("Error\nInvalide number of arguments!\n");
	return (0);
}
