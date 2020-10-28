/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:38:44 by tidminta          #+#    #+#             */
/*   Updated: 2020/10/28 15:06:55 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int				ft_get_start_position(t_mapinfos *map, char **tab, int i, int j)
{
	int		cpt;
	int		ret;

	cpt = 0;
	while ((tab[++i] && (i < (int)map->line_max - 1)))
	{
		j = -1;
		if (!(ret = ft_is_map_line(tab[i])))
			return (0);
		while (tab[i][++j])
		{
			if (tab[i][j] == 'N' || tab[i][j] == 'S' || tab[i][j] == 'E'
				|| tab[i][j] == 'W')
			{
				map->start_x = j;
				map->start_y = i;
				map->dir = tab[i][j];
				tab[i][j] = '0';
				cpt++;
			}
		}
	}
	if (cpt == 1)
		return (1);
	return (-1);
}

static void		ft_get_dir2(t_player *p, char c)
{
	if (c == 'N')
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
	if (c == 'S')
	{
		p->dirx = 0;
		p->diry = -1;
		p->planx = -0.66;
		p->plany = 0;
	}
	else if (c == 'W')
	{
		p->dirx = -1;
		p->diry = 0;
		p->planx = 0;
		p->plany = 0.66;
	}
	else
		ft_get_dir2(p, c);
}

int				ft_check_path(t_mapinfos *m, t_list *lst_tmp, t_text **text)
{
	int		i;
	int		ret;

	i = 0;
	if ((!m->res->x || m->res->x <= 0) ||
		(!m->res->y || m->res->y <= 0))
		ft_error(&(m)->garbage, "Error\nBad resolution.\n", -1, NULL);
	if (ft_get_path("NO", lst_tmp, &text[0]->path) < 0)
		return (0);
	if (ft_get_path("SO", lst_tmp, &text[1]->path) < 0)
		return (0);
	if (ft_get_path("WE", lst_tmp, &text[2]->path) < 0)
		return (0);
	if (ft_get_path("EA", lst_tmp, &text[3]->path) < 0)
		return (0);
	if (ft_get_path("S ", lst_tmp, &text[4]->path) < 0)
		return (0);
	while (i < 5)
	{
		if ((ret = open(text[i]->path, O_RDONLY)) < 0)
			return (0);
		close(ret);
		i++;
	}
	return (1);
}

int				ft_get_index(t_player *p)
{
	if ((p->side == 1) && (p->raydy < 0))
		return (0);
	else if ((p->side == 0) && (p->raydx < 0))
		return (3);
	else if ((p->side == 0) && (p->raydx > 0))
		return (2);
	else
		return (1);
}
