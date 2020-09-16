/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:38:44 by tidminta          #+#    #+#             */
/*   Updated: 2020/09/16 17:01:32 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int				ft_get_start_position(t_mapinfos *map)
{
	char	**tab;
	size_t	i;
	size_t	j;

	i = -1;
	tab = map->map_tab;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == 'N' || tab[i][j] == 'S' || tab[i][j] == 'E'
				|| tab[i][j] == 'W')
			{
				map->start_x = j;
				map->start_y = i;
				map->dir = tab[i][j];
				return (1);
			}
		}
	}
	return (0);
}

static void		ft_get_dir2(t_player *p, char c)
{
	if (c == 'S')
	{
		p->dirx = 0;
		p->diry = 1;
		p->planx = 0.66;
		p->plany = 0;
	}
	else
	{
		p->dirx = 1;
		p->diry = 0;
		p->planx = 0;
		p->plany = -0.66;
	}
}

void		ft_get_dir(t_mapinfos *map)
{
	char		c;
	t_player	*p;

	c = map->dir;
	p = map->p;
	if (c == 'N')
	{
		p->dirx = 0;
		p->diry = -1;
		p->planx = -0.66;
		p->plany = 0;
	}
	else if (c == 'E')
	{
		p->dirx = -1;
		p->diry = 0;
		p->planx = 0;
		p->plany = 0.66;
	}
	else
		ft_get_dir2(p, c);
}
