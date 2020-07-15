/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:42:32 by tidminta          #+#    #+#             */
/*   Updated: 2020/07/15 19:27:07 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub.h"
// #include "mlx/mlx.h"

/*
*************************************
**			  	MAIN              **
**     PENSER A TOUT FREE         **
*************************************
*/

int				main(int ac, char **av)
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
		p = ft_playerinit();
		mlx = ft_start_mlx(map);
		map->p = &p;
		ft_raycast(&map, &mlx, p);
		close(fd);
		system("leaks Cub3D");
		return (0);
	}
	ft_printf("Error\nInvalide number of arguments!\n");
	return (0);
}

