/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:55:48 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/29 11:05:06 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

size_t			ft_check_rfc(t_mapinfos *map)
{
	if (map->resolution->res_x < 0 || map->resolution->res_y < 0
		|| map->floor->bleue < 0 || map->floor->green < 0
			|| map->floor->red < 0 || map->ceil->red < 0 ||
				map->ceil->red < 0 || map->ceil->red <0 ||
					map->ceil->bleue < 0)
						return (0);
	return (1);
}

