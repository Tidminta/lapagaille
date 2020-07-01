/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:42:32 by tidminta          #+#    #+#             */
/*   Updated: 2020/07/01 19:17:44 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub.h"
#include "mlx/mlx.h"

int				main(int ac, char **av)
{
	t_list		*list;
	t_mapinfos	*map;
	t_mlx		*mlx;
	int			fd;

	if (ac == 2)
	{
		list = NULL;
		mlx = NULL;
		if ((fd = ft_parse_open(av, &map, &list)) < 0)
			return (0);
		// mlx = ft_start_mlx();
		// mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img->img_ptr, 0, 0);
		// mlx_loop(mlx->mlx_ptr);
		// free(mlx);
		// free(mlx->img);
		close(fd);
		system("leaks Cub3D");
		return (0);
	}
	ft_printf("Error\nInvalide number of arguments!\n");
	return (0);
}
