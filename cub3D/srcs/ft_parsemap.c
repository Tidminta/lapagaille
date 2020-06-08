/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 13:00:34 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/08 20:47:01 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/libftprintf.h"

size_t		ft_get_res_x(t_list *infos, t_res *res)
{
	char		*tmp;
	size_t		i;
	size_t		j;

	while (infos->next)
	{
		i = 1;
		j = 0;
		tmp = infos->content;
		if (tmp[0] == 'R')
		{
			while ((tmp[i] < '0' || tmp[i] > '9'))
			{
				i++;
			}
			while ((tmp[i + j] >= '0' && tmp[i + j] <= '9'))
			{
				j++;
			}
			res->res_x = ft_atoi(ft_substr(tmp, i, j));
			return (1);
		}
		infos = infos->next;
	}
	return (0);
}

size_t		ft_get_res_y(t_list *infos, t_res *res)
{
	size_t	len;
	size_t	i;
	char	*tmp;

	while (infos->next)
	{
		tmp = infos->content;
		if (tmp[0] == 'R')
		{
			len = ft_strlen(tmp);
			i = len;
			while ((tmp[i] < '0' || tmp[i] > '9'))
			{
				i--;
			}
			while ((tmp[i] >= '0' && tmp[i] <= '9'))
			{
				i--;
			}
			res->res_y = ft_atoi(ft_substr(tmp, i, (len - i)));
			return (1);
		}
		infos = infos->next;
	}
	return (0);
}

t_list		*ft_map_gnl(int fd)
{
	int			ret;
	t_list		*map;
	t_list		*tmp;
	char		*line;

	map = ft_lstnew("Start");
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (line[0])
		{
			tmp = ft_lstnew((void*)line);
			ft_lstadd_back(&map, tmp);
		}
	}
	return (map);
}

size_t		ft_get_path(char *to_find, t_list *lst, char **s)
{
	int		i;
	int		j;
	char	*tmp;
	char	**tab;

	j = 0;
	while (lst->next)
	{
		tmp = lst->content;
		tab = ft_split(tmp, ' ');
		while (tab[i])
		{
			if (ft_strncmp(to_find, tab[i], 2) == 0)
			{
				i++;
				*s = ft_strdup(tab[i]);
				return (1);
			}
			i++;
		}
		free(tab);
		i = 0;
		lst = lst->next;
	}
	return (0);
}

size_t		ft_parsemap(t_list *list, t_mapinfos *map, int fd)
{
	(void)map;
	list = ft_map_gnl(fd);
	// ft_print_list(list);
	map->resolution = (t_res*)malloc(sizeof(t_res));
	map->floor = (t_rgb*)malloc(sizeof(t_rgb));
	map->ceil = (t_rgb*)malloc(sizeof(t_rgb));
	ft_get_res_x(list, map->resolution);
	ft_get_res_y(list, map->resolution);
	ft_get_path("NO", list, &map->no);
	printf("[pathtest][%s]\n", map->no);
	ft_get_path("SO", list, &map->so);
	ft_get_path("WE", list, &map->we);
	ft_get_path("EA", list, &map->ea);
	ft_get_path("S", list, &map->sprite);
	ft_print_mapinfos(map);
	return (1);
}
