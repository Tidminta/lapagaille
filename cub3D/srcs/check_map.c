/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:38:44 by tidminta          #+#    #+#             */
/*   Updated: 2020/10/13 13:51:37 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int				ft_get_start_position(t_mapinfos *map, char **tab)
{
	int		cpt;
	int		ret;
	size_t	i;
	size_t	j;

	i = -1;
	cpt = 0;
	ret = 0;
	while ((tab[++i] && (i < map->line_max - 1)))
	{
		j = -1;
		if (!(ret = ft_is_map_line(tab[i])))
		{
			return (0);
		}
		while (tab[i][++j])
		{
			if (tab[i][j] == 'N' || tab[i][j] == 'S' || tab[i][j] == 'E'
				|| tab[i][j] == 'W')
			{
				map->start_x = j;
				map->start_y = i;
				map->dir = tab[i][j];
				if (++cpt > 1)
					return (0);
			}
		}
	}
	return (1);
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

void			ft_get_dir(t_mapinfos *map)
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

int				ft_check_path(t_list *lst_tmp, t_text **text)
{
	if (ft_get_path("NO", lst_tmp, &text[0]->path) < 0)
		return (-1);
	if (ft_get_path("SO", lst_tmp, &text[1]->path) < 0)
		return (-1);
	if (ft_get_path("WE", lst_tmp, &text[2]->path) < 0)
		return (-1);
	if (ft_get_path("EA", lst_tmp, &text[3]->path) < 0)
		return (-1);
	if (ft_get_path("S ", lst_tmp, &text[4]->path) < 0)
		return (-1);
	return (1);
}

int						ft_get_index(t_player *p)
{
	/** NO **/
	if ((p->side == 1) && (p->raydy < 0))
		return (0);
	/** EA **/
	else if ((p->side == 0) && (p->raydx < 0))
		return (3);
	/** WE **/
	else if ((p->side == 0) && (p->raydx > 0))
		return (2);
	/** SO **/
	else
		return (1);
}
