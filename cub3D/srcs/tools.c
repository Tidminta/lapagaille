/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:57:50 by tidminta          #+#    #+#             */
/*   Updated: 2020/10/20 17:14:12 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void			ft_clear_map(t_mapinfos *map)
{
	ft_freelst(map->map);
	free(map->map_tab);
	free(map->text[0]->path);
	free(map->text[1]->path);
	free(map->text[2]->path);
	free(map->text[3]->path);
	free(map->text[4]->path);
	free(map->mlx->img);
	free(map->mlx);
	mlx_destroy_window(map->mlx->mlx_p, map->mlx->win);
}
