/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 14:08:59 by tidminta          #+#    #+#             */
/*   Updated: 2020/07/21 15:53:19 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int				ft_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}


int				ft_dealkey(int key, t_mapinfos **map_tmp)
{
	t_mapinfos *map;
	t_player	*p;
	t_mlx		*mlx2;

	map = *map_tmp;
	p = map->p;
	mlx2 = map->mlx;
	if (key == 13)
		ft_set_forward(&map);
	else if (key == 53)
	{
		ft_printf("ECHAP\n");
		mlx_destroy_window(map->mlx->mlx_p, map->mlx->win);
		exit(EXIT_SUCCESS);
	}
	else
		printf("[KEY][%d]\n", key);
	return (0);
}
