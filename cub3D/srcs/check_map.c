/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:38:44 by tidminta          #+#    #+#             */
/*   Updated: 2020/08/05 17:37:39 by tidminta         ###   ########.fr       */
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

int				ft_free(t_mapinfos *map)
{
	free(map->mlx);
	free(map->p);
	free(map->res);
	free(map->map);
	free(map->no);
	free(map->so);
	free(map->we);
	free(map->ea);
	return (0);
}
