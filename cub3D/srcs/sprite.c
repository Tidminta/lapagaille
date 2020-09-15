/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:37:01 by tidminta          #+#    #+#             */
/*   Updated: 2020/09/15 17:03:20 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/*
******************************************
**			  CUB3D                		**
**			SPRITES INIT		   		**
**			L41-48 p.e pas necessaire	**
******************************************
*/

int				ft_sprites_init(t_mapinfos *map)
{
	int		nb;
	int		i;
	int		j;

	nb = 0;
	i = -1;
	while (map->map_tab[++i])
	{
		j = -1;
		while (map->map_tab[i][++j])
		{
			if (map->map_tab[i][j] == '2')
				nb++;
		}
	}
	map->nbspt = nb;
	if (!(map->sprites = (t_sprite**)malloc(sizeof(t_sprite) * (nb))))
		return (-1);
	while (--nb >= 0)
	{
		map->sprites[nb] = (t_sprite*)malloc(sizeof(t_sprite));
		if (!map->sprites[nb])
			return (-1);
	}
	return (nb);
}

void			ft_sprite_infos(t_mapinfos *map)
{
	int		i;
	int		j;
	int		nb;
	
	nb = 0;
	i = -1;
	while (map->map_tab[++i])
	{
		j = -1;
		while (map->map_tab[i][++j])
		{
			if (map->map_tab[i][j] == '2')
			{
				map->sprites[nb]->x = j;
				map->sprites[nb++]->y = i;
			}
		}
	}
}

static void			ft_spritesrt(map)
{
	
}


void				ft_spritecast(t_mapinfos *map)
{
	ft_spritesrt(map);
}
