/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:37:01 by tidminta          #+#    #+#             */
/*   Updated: 2020/09/15 20:15:38 by tidminta         ###   ########.fr       */
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
			if (map->map_tab[i][j] == '2')
				nb++;
	}
	map->nbspt = nb;
	if (!(map->spinfos->sp = (t_sprite**)malloc(sizeof(t_sprite) * (nb))))
		return (-1);
	while (--nb >= 0)
		if (!(map->spinfos->sp[nb] = (t_sprite*)malloc(sizeof(t_sprite))))
			return (-1);
	map->spinfos->sporder = (int*)malloc(sizeof(int) * map->nbspt);
	map->spinfos->spdist = (double*)malloc(sizeof(double) * map->nbspt);
	if (!map->spinfos->sporder || !map->spinfos->spdist)
		return (-1);
	ft_bzero(map->spinfos->sporder, (size_t)map->nbspt);
	ft_bzero(map->spinfos->spdist, (size_t)map->nbspt);
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
				map->spinfos->sp[nb]->y = i;
				map->spinfos->sp[nb]->x = j;
				nb++;
			}
		}
	}
}

static void			ft_spritesort(t_mapinfos *map)
{
	t_player	*p;
	t_sprite	**s;
	int			i;
	int			j;
	double		tmp;

	p = map->p;
	s = map->spinfos->sp;
	i = -1;
	tmp = 0.0;
	printf("\n -- AVANT --\n");
	while (++i < map->nbspt)
	{
		map->spinfos->sporder[i] = i;
		map->spinfos->spdist[i] = ((p->posx - s[i]->x) * (p->posx - s[i]->x) +
			(p->posy - s[i]->y) * (p->posy - s[i]->y));
		printf("[%f]\n", map->spinfos->spdist[i]);
	}
	i = -1;
	while (++i < map->nbspt)
	{
		j = i + 1;
		while (j <= map->nbspt)
		{
			if (map->spinfos->spdist[i] < map->spinfos->spdist[j])
			{
				tmp = map->spinfos->spdist[i];
				map->spinfos->spdist[i] = map->spinfos->spdist[j];
				map->spinfos->spdist[j] = tmp;
			}
			j++;
		}
	}
	printf("\n -- APRES --\n");
	i = -1;
	while (++i < map->nbspt)
		printf("[%f]\n", map->spinfos->spdist[i]);
}

void				ft_spritecast(t_mapinfos *map)
{
	ft_sprites_init(map);
	ft_sprite_infos(map);
	ft_spritesort(map);
}
