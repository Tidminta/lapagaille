/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:57:50 by tidminta          #+#    #+#             */
/*   Updated: 2020/10/21 19:12:58 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void			ft_clear_map(t_mapinfos *map)
{
	if (map->map)
		ft_freelst(map->map);
	if (map->map_tab)
	{
		free(map->map_tab);
	}
	if (map->text)
	{
		free(map->text[0]->path);
		free(map->text[1]->path);
		free(map->text[2]->path);
		free(map->text[3]->path);
		free(map->text[4]->path);
	}
	if (map->mlx)
	{
		free(map->mlx->img);
		free(map->mlx);
		mlx_destroy_window(map->mlx->mlx_p, map->mlx->win);
	}
}

void		ft_print_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		printf("[%zu][%s]\n", i, tab[i]);
		i++;
	}
}

int			ft_quit(int button, t_mapinfos **map)
{
	(void)map;
	if (button < 0)
	{
		ft_clear_map((*map));
		ft_error(&(*map)->garbage, NULL, 0, (*map));
	}
	return (0);
}

// int			ft_map_is_closed(t_mapinfos *map, char **tab, int res)
// {
// 	int i;
// 	int j;

// 	if (!res || res < 0)
// 		return (0);
// 	i = -1;
// 	while (tab[++i])
// 	{
// 		if (ft_strlen(tab[i]) < (size_t)res)
// 		{
			
// 		}
// 	}
// }

