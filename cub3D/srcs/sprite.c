/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:37:01 by tidminta          #+#    #+#             */
/*   Updated: 2020/09/25 16:06:48 by tidminta         ###   ########.fr       */
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
	while (++i < map->nbsp)
		if (!(map->spinfos->sp[i] = (t_sprite*)malloc(sizeof(t_sprite))))
			return (-1);
	// map->spinfos->sporder = (int*)malloc(sizeof(int) * map->nbsp);
	// map->spinfos->spdist = (double*)malloc(sizeof(double) * map->nbsp);
	// if (!map->spinfos->sporder || !map->spinfos->spdist)
	// 	return (-1);
	// ft_bzero(map->spinfos->sporder, (size_t)map->nbsp);
	// ft_bzero(map->spinfos->spdist, (size_t)map->nbsp);
	i = -1;
	while (++i < nb)
	{
		map->spinfos->sp[i]->spx = 0;
		map->spinfos->sp[i]->spy = 0;
		map->spinfos->sp[i]->invdet = 0;
		map->spinfos->sp[i]->transx = 0;
		map->spinfos->sp[i]->transy = 0;
		map->spinfos->sp[i]->spscreenx = 0;
		map->spinfos->sp[i]->spheight = 0;
		map->spinfos->sp[i]->startx = 0;
		map->spinfos->sp[i]->starty = 0;
		map->spinfos->sp[i]->endx = 0;
		map->spinfos->sp[i]->endy = 0;
		map->spinfos->sp[i]->spwidth = 0;
		map->spinfos->sp[i]->stripe = 0;
		map->spinfos->sp[i]->texx = 0;
		map->spinfos->sp[i]->texy = 0;
		map->spinfos->sp[i]->d = 0;
	}
	return (1);
}

void				ft_fill_sprites(t_mapinfos *map)
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

// void				ft_spritesort(t_mapinfos *map)
// {
// 	t_player	*p;
// 	t_sprite	**sp;
// 	t_sprite	*tmp;
// 	int			i;
// 	int			j;

// 	p = map->p;
// 	sp = map->spinfos->sp;
// 	i = 0;
// 	printf("in sprite sort ...\n");
// 	while (sp[i])
// 	{
// 		j = i + 1;
// 		while (sp[j])
// 		{
// 			if (sp[i]->dist < sp[j]->dist)
// 			{
// 				tmp = sp[i];
// 				sp[i] = sp[j];
// 				sp[j] = tmp;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	printf("sprite sorted ...\n");
// }

int					ft_sprite_cpt(t_mapinfos *map)
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

void				ft_spritecast(t_mapinfos *map)
{
	ft_fill_sprites(map);
	// printf("fill sprites ...\n");
	// ft_spritesort(map);
	// printf("sprite sorting ...\n");
	ft_sprites_projections(map);
	// printf("sprite projection ...\n");
}
