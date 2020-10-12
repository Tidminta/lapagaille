/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 15:59:58 by tidminta          #+#    #+#             */
/*   Updated: 2020/10/12 19:06:16 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int				ft_keypress(int key, t_mapinfos **map_tmp)
{
	t_mapinfos	*map;
	t_player	*p;
	t_mlx		*mlx2;

	map = *map_tmp;
	p = map->p;
	mlx2 = map->mlx;
	if (key == 13 || key == 126)
		p->m_up = 1;
	else if (key == 1 || key == 125)
		p->m_down = 1;
	else if (key == 0)
		p->m_left = 1;
	else if (key == 2)
		p->m_right = 1;
	else if (key == 123)
		p->m_left_key = 1;
	else if (key == 124)
		p->m_right_key = 1;
	else if (key == 53)
	{
		printf("ECHAP\n");
		mlx_destroy_window(map->mlx->mlx_p, map->mlx->win);
		return (ft_error(&map->garbage, 0));
	}
	return (0);
}

int				ft_keyrelease(int key, t_mapinfos **map_tmp)
{
	t_mapinfos	*map;
	t_player	*p;
	t_mlx		*mlx2;

	map = *map_tmp;
	p = map->p;
	mlx2 = map->mlx;
	if (key == 13 || key == 126)
		p->m_up = 0;
	else if (key == 1 || key == 125)
		p->m_down = 0;
	else if (key == 0)
		p->m_left = 0;
	else if (key == 2)
		p->m_right = 0;
	else if (key == 123)
		p->m_left_key = 0;
	else if (key == 124)
		p->m_right_key = 0;
	return (0);
}

void			ft_lateral_move(t_mapinfos *map, int indice)
{
	t_player	*p;
	char		**map2d;

	p = map->p;
	map2d = map->map_tab;
	if (indice == 0)
	{
		if (map2d[(int)p->posy]
			[(int)(p->posx - p->planx * p->movespeed)] == '0')
			p->posx += (p->planx * p->movespeed);
		if (map2d[(int)(p->posy + p->plany * p->movespeed)]
			[(int)p->posx] == '0')
			p->posy += (p->plany * p->movespeed);
	}
	else
	{
		if (map2d[(int)p->posy]
		[(int)(p->posx - p->planx * p->movespeed)] == '0')
			p->posx -= (p->planx * p->movespeed);
		if (map2d[(int)(p->posy + p->plany * p->movespeed)]
		[(int)p->posx] == '0')
			p->posy -= (p->plany * p->movespeed);
	}
}
