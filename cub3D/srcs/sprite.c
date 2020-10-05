/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:37:01 by tidminta          #+#    #+#             */
/*   Updated: 2020/09/30 15:41:42 by tidminta         ###   ########.fr       */
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
				sp[nb]->y = i + 0.5;
				sp[nb]->x = j + 0.5;
				map->spinfos->sp[nb]->dist = ((map->p->posx - (sp[nb]->x + 0.5)) *
					(map->p->posx - (sp[nb]->x + 0.5)) + (map->p->posy - (sp[nb]->y + 0.5))
						* (map->p->posy - (sp[nb]->y + 0.5)));
				nb++;
			}
		}
	}
}

void				ft_spritesort(t_mapinfos *map)
{
	t_player	*p;
	t_sprite	**sp;
	t_sprite	*tmp;
	int			i;
	int			j;

	p = map->p;
	sp = map->spinfos->sp;
	i = 0;
	printf("in sprite sort ...\n");
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
	printf("sprite sorted ...\n");
}

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
	// ft_spritesort(map);
	ft_sprites_projections(map);
}
