/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:37:01 by tidminta          #+#    #+#             */
/*   Updated: 2020/09/16 18:47:59 by tidminta         ###   ########.fr       */
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

static int				ft_sprites_init(t_mapinfos *map)
{
	int		i;
	int		nb;

	i = -1;
	nb = map->nbsp;
	if (!(map->spinfos->sp = (t_sprite**)malloc(sizeof(t_sprite) * (nb))))
		return (-1);
	while (--nb >= 0)
		if (!(map->spinfos->sp[nb] = (t_sprite*)malloc(sizeof(t_sprite))))
			return (-1);
	// map->spinfos->sporder = (int*)malloc(sizeof(int) * map->nbsp);
	// map->spinfos->spdist = (double*)malloc(sizeof(double) * map->nbsp);
	// if (!map->spinfos->sporder || !map->spinfos->spdist)
	// 	return (-1);
	// ft_bzero(map->spinfos->sporder, (size_t)map->nbsp);
	// ft_bzero(map->spinfos->spdist, (size_t)map->nbsp);
	map->spinfos->invdet = 0;
	map->spinfos->transx = 0;
	map->spinfos->transy = 0;
	map->spinfos->spscreenx = 0;
	map->spinfos->spheight = 0;
	map->spinfos->startx = 0;
	map->spinfos->starty = 0;
	map->spinfos->endx = 0;
	map->spinfos->endy = 0;
	map->spinfos->spwidth = 0;
	map->spinfos->stripe = 0;
	map->spinfos->texx = 0;
	map->spinfos->texy = 0;
	map->spinfos->d = 0;
	return (1);
}

static void				ft_fill_sprites(t_mapinfos *map)
{
	int			i;
	int			j;
	int			nb;
	t_sprite	**sp;

	nb = 0;
	i = -1;
	sp = map->spinfos->sp;
	while (map->map_tab[++i])
	{
		j = -1;
		while (map->map_tab[i][++j])
		{
			if (map->map_tab[i][j] == '2')
			{
				sp[nb]->y = i;
				sp[nb]->x = j;
				map->spinfos->sp[nb]->dist = ((map->p->posx - sp[nb]->x) *
					(map->p->posx - sp[nb]->x) + (map->p->posy - sp[nb]->y)
						* (map->p->posy - sp[nb]->y));
				nb++;
			}
		}
	}
}

static void				ft_spritesort(t_mapinfos *map)
{
	t_player	*p;
	t_sprite	**sp;
	t_sprite	*tmp;
	int			i;
	int			j;

	p = map->p;
	sp = map->spinfos->sp;
	i = 0;
	while (sp[i])
	{
		j = i + 1;
		while (sp[j])
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

int					ft_sprite_cpt(t_mapinfos *map)
{
	int i;
	int j;
	int nb;

	i = -1;
	nb = 0;
	while (map->map_tab[++i])
	{
		j = -1;
		while (map->map_tab[i][++j])
			if (map->map_tab[i][j] == '2')
				nb++;
	}
	map->nbsp = nb;
	return (ft_sprites_init(map));
}

void				ft_spritecast(t_mapinfos *map)
{
	ft_fill_sprites(map);
	ft_spritesort(map);
	// ft_sprites_projections(map);
}
