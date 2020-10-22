/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:57:50 by tidminta          #+#    #+#             */
/*   Updated: 2020/10/22 17:46:36 by tidminta         ###   ########.fr       */
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
	printf("* * * PRINT TAB * * *\n");
	while (tab[i])
	{
		printf("[%zu][%s]\n", i, tab[i]);
		i++;
	}
	printf("* * * END * * *\n");
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

static int			ft_check_row(char **tab, t_mapinfos *map)
{
	size_t len_max;
	int	i;
	int	j;

	i = 1;
	j = 0;
	len_max = map->col_max;
	while (i < (int)map->line_max)
	{
		while (tab[i][j])
		{
			if (tab[i][j] == '1' || tab[i][j] == '*')
				j++;
			else
				return (0);
		}
		i += len_max - 1;
		j = 0;
	}
	return (1);
}

static int		ft_check_col(char **tab, t_mapinfos *map)
{
	size_t	col_max;
	size_t	line_max;
	int		i;
	int		j;

	i = 1;
	j = 0;
	col_max = map->col_max;
	line_max = map->line_max;
	while (i < line_max)
	{
		while (j < (int)col_max)
		{
			j = 0;
			if (tab[i][j] != '1' || tab[i][j] != '*')
				return (0);
			j += col_max;
		}
		i++;
	}
	return (1);
}

// static			ft_check_into(char **tab, t_mapinfos *map)
// {
	
// }

int			ft_map_is_closed(t_mapinfos *map, char **tab, int res)
{
	char	**tmp;
	size_t	i;
	size_t	j;
	size_t	len_max;
	size_t	len_tab;

	if (!res || res < 0)
		return (0);
	i = -1;
	len_max = map->line_max;
	tmp = (char**)malloc(sizeof(char*) * map->line_max + 1);
	tmp[map->res->x] = 0;
	while (tab[++i])
	{
		len_tab = ft_strlen(tab[i]);
		if (len_tab < len_max)
		{
			tmp[i] = (char*)ft_calloc(len_max + 1, sizeof(char));
			tmp[i][len_max] = 0;
			j = -1;
			while (++j < len_max)
			{
				if (j < len_tab && (tab[i][j] == '1' || tab[i][j] == '2' || tab[i][j] == '0'))
					tmp[i][j] = tab[i][j];
				else
					tmp[i][j] = '*';
			}
		}
		else
			tmp[i] = ft_strdup(tab[i]);
	}
	ft_print_tab(tmp);
	if (!(ft_check_row(tmp, map)) || !ft_check_col(tmp, map))
		printf("ERROR MAP NOT CLOSED\n");
	else
		printf("MAP CLOSED\n");
	exit (0);
}
