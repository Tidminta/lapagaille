/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:57:50 by tidminta          #+#    #+#             */
/*   Updated: 2020/10/26 18:43:21 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static int			ft_check_row(char **tab, t_mapinfos *map)
{
	size_t	len_max;
	int		i;
	int		j;

	i = 1;
	j = 0;
	len_max = map->col_max;
	while ((size_t)i < map->line_max)
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

static int			ft_check_col(char **tab, t_mapinfos *map)
{
	size_t	col_max;
	size_t	line_max;
	int		i;
	int		j;

	i = 1;
	col_max = map->col_max;
	line_max = map->line_max;
	while (i < (int)line_max)
	{
		j = 0;
		if (tab[i][j] != '1' && tab[i][j] != '*')
			return (0);
		j += (int)col_max - 1;
		if (tab[i][j] != '1' && tab[i][j] != '*')
			return (0);
		i++;
	}
	return (1);
}

static	int			ft_check_zero(char **t, size_t i, size_t j)
{
	if (t[i - 1][j] != '1' && t[i - 1][j] != '0' && t[i - 1][j] != '2')
		return (0);
	else if (t[i + 1][j] != '1' && t[i + 1][j] != '0' && t[i + 1][j] != '2')
		return (0);
	else if (t[i][j - 1] != '1' && t[i][j - 1] != '0' && t[i][j - 1] != '2')
		return (0);
	else if (t[i][j + 1] != '1' && t[i][j + 1] != '0' && t[i][j + 1] != '2')
		return (0);
	return (1);
}

static	int			ft_check_into(char **tab, t_mapinfos *map)
{
	size_t	col_max;
	size_t	line_max;
	int		i;
	int		j;

	col_max = map->col_max;
	line_max = map->line_max;
	i = 2;
	j = 0;
	while (i < ((int)line_max - 2))
	{
		j = 1;
		while (j < (int)col_max)
		{
			if (tab[i][j] == '0' || tab[i][i] == '2')
			{
				if (!(ft_check_zero(tab, i, j)))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int					ft_map_is_closed(t_mapinfos *map, char **tab)
{
	char	**tmp;
	size_t	i;
	size_t	j;

	i = -1;
	tmp = (char**)ft_calloc(map->line_max + 1, sizeof(char*));
	while (tab[++i])
	{
		if (ft_strlen(tab[i]) < map->line_max)
		{
			tmp[i] = (char*)ft_calloc(map->line_max + 1, sizeof(char));
			j = -1;
			ft_fill_tab(map, i, tab, tmp);
		}
		else
			tmp[i] = ft_strdup(tab[i]);
	}
	if ((!ft_check_row(tmp, map)) || (!ft_check_col(tmp, map))
		|| (!ft_check_into(tmp, map)))
	{
		ft_free_split(tmp);
		return (0);
	}
	ft_free_split(tmp);
	return (1);
}
