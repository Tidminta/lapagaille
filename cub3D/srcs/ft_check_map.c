/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:38:44 by tidminta          #+#    #+#             */
/*   Updated: 2020/07/02 15:14:26 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void			ft_free_split(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

size_t			ft_check_rfc(t_mapinfos *map)
{
	if (map->resolution->res_x < 0 || map->resolution->res_y < 0
			|| map->floor->bleue < 0 || map->floor->green < 0
					|| map->floor->red < 0 || map->ceil->red < 0 ||
							map->ceil->red < 0 || map->ceil->red < 0 ||
									map->ceil->bleue < 0)
		return (0);
	return (1);
}

int				ft_get_start_position(t_mapinfos *map)
{
	char	**tab;
	size_t	i;
	size_t	j;

	i = 0;
	tab = map->map_tab;
	while (tab[i++])
	{
		j = 0;
		while (tab[i][j++])
		{
			if (tab[i][j] == 'N' || tab[i][j] == 'S' || tab[i][j] == 'E'
				|| tab[i][j] == 'W')
			{
				map->start_x = j;
				map->start_y = i;
				return (1);
			}
		}
	}
	return (0);
}
