/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:42:32 by tidminta          #+#    #+#             */
/*   Updated: 2020/08/07 17:02:12 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int					ft_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static int			ft_game_loop(t_mapinfos *map)
{
	t_mlx		*mlx;

	mlx = map->mlx;
	mlx->img->img_p = mlx_new_image(map->mlx->mlx_p, map->res->x, map->res->y);
	mlx->img->data = (int *)mlx_get_data_addr(mlx->img->img_p, &mlx->img->bpp,
			&mlx->img->size_l, &mlx->img->endian);
	ft_init_text(map);
	ft_setmove(map);
	ft_raycast(map, mlx, map->p);
	ft_print_playerinfos(map->p);
	mlx_clear_window(map->mlx->mlx_p, map->mlx->win);
	mlx_put_image_to_window(mlx->mlx_p, mlx->win, mlx->img->img_p, 0, 0);
	mlx_destroy_image(mlx->mlx_p, mlx->img->img_p);
	mlx_destroy_image(mlx->mlx_p, map->no->img_p);
	return (0);
}

/*
**************************************
**			  	MAIN              	**
** 		-g3 -fsanitize=address      **
**		system("leaks Cub3D");      **
**		refaire ft_free			    **
**		refaire ft_printplayerinfos **
**	RECAP : SET DIR DONE            **
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
		if (!(p = ft_playerinit()))
			return (0);
		if (!(mlx = ft_start_mlx(map, p)))
			return (0);
		// ft_set_dir(p);
		mlx_hook(mlx->win, KEYPRESS, KEYPRESSMASK, ft_keypress, &map);
		mlx_hook(mlx->win, KEYRELEASE, KEYRELEASEMASK, ft_keyrelease, &map);
		mlx_loop_hook(mlx->mlx_p, &ft_game_loop, map);
		mlx_loop(mlx->mlx_p);
		close(fd);
		return (0);
	}
	printf("Error\nInvalide number of arguments!\n");
	return (0);
}
