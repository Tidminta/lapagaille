/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:37:01 by tidminta          #+#    #+#             */
/*   Updated: 2020/10/06 19:48:39 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/*
******************************************
**			  CUB3D                		**
**			SPRITES INIT		   		**
******************************************
*/

static int				ft_sprites_init(t_mapinfos *map)
{
	int		i;
	int		nb;

	i = -1;
	nb = map->nbsp;
	if (!(map->spinfos->sp = (t_sprite**)malloc(sizeof(t_sprite) * (nb))))
		return (-1);
	while (++i < map->nbsp)
		if (!(map->spinfos->sp[i] = (t_sprite*)malloc(sizeof(t_sprite))))
			return (-1);
	// i = -1;
	// while (++i < nb)
	// 	ft_bzero(map->spinfos->sp[i], (size_t)map->nbsp);
	return (1);
}

void					ft_fill_sprites(t_mapinfos *map, int nb)
{
	int			i;
	int			j;
	t_sprite	**sp;

	i = -1;
	sp = map->spinfos->sp;
	while (map->map_tab[++i])
	{
		j = -1;
		while (map->map_tab[i][++j])
		{
			if (map->map_tab[i][j] == '2')
			{
				sp[nb]->y = i + 0.5;
				sp[nb]->x = j + 0.5;
				map->spinfos->sp[nb]->dist =
					((map->p->posx - (sp[nb]->x + 0.5)) *
					(map->p->posx - (sp[nb]->x + 0.5))
						+ (map->p->posy - (sp[nb]->y + 0.5))
							* (map->p->posy - (sp[nb]->y + 0.5)));
				nb++;
			}
		}
	}
}

void					ft_spritesort(t_mapinfos *map)
{
	t_player	*p;
	t_sprite	**sp;
	t_sprite	*tmp;
	int			i;
	int			j;

	p = map->p;
	sp = map->spinfos->sp;
	i = 0;
	while (i < map->nbsp)
	{
		j = i + 1;
		while (j < map->nbsp)
		{
			if (sp[i]->dist < sp[j]->dist)
			{
				tmp = sp[i];
				sp[i] = sp[j];
				sp[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int						ft_sprite_cpt(t_mapinfos *map)
{
	int i;
	int j;
	int nb;

	i = 0;
	nb = 0;
	while (map->map_tab[i])
	{
		j = 0;
		while (map->map_tab[i][j])
		{
			if (map->map_tab[i][j] == '2')
				nb++;
			j++;
		}
		i++;
	}
	map->nbsp = nb;
	return (ft_sprites_init(map));
}

void					ft_spritecast(t_mapinfos *map)
{
	ft_fill_sprites(map, 0);
	ft_spritesort(map);
	ft_sprites_projections(map);
}
