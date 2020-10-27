/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 18:40:33 by tidminta          #+#    #+#             */
/*   Updated: 2020/10/27 19:37:21 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void		ft_clear_map(t_mapinfos *map)
{
	if (map->map)
		ft_freelst(map->map);
	if (map->map_tab)
		free(map->map_tab);
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

void		ft_fill_tab(t_mapinfos *map, size_t i, char **tab, char **tmp)
{
	size_t j;

	j = -1;
	while (++j < map->line_max - 1)
	{
		if (j < ft_strlen(tab[i]) && (tab[i][j] == '1' ||
			tab[i][j] == '2' || tab[i][j] == '0'))
			tmp[i][j] = tab[i][j];
		else
			tmp[i][j] = '*';
	}
}

void		ft_screen_shoot(t_mapinfos *map)
{
	int	fd;

	if ((fd = open("save.bmp",
		O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) < 0)
		ft_error(&map->garbage, "Error\nScreenshot failled 1!", 0, map);
	close(fd);
	ft_create_bmp(map);
}
