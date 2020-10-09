/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 13:00:34 by tidminta          #+#    #+#             */
/*   Updated: 2020/10/09 16:20:55 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int					ft_get_res_x(t_list *infos, t_res *res)
{
	char			*tmp;
	size_t			i;
	size_t			j;

	while (infos->next)
	{
		i = -1;
		j = -1;
		tmp = infos->content;
		while (tmp[++i] != 'R')
			;
		if (tmp[i] == 'R')
		{
			while (tmp[++i] && (tmp[i] < '0' || tmp[i] > '9'))
				if (tmp[i] == '-')
					return (-1);
			while ((tmp[i + (++j)] >= '0' && tmp[i + j] <= '9'))
				res->x = (res->x * 10) + (tmp[i + j] - 48);
			res->x = (res->x <= 0) ? -1 : res->x;
			return (i + j);
		}
		infos = infos->next;
	}
	return (0);
}

int					ft_get_res_y(t_list *infos, t_res *res, int index)
{
	size_t	i;
	char	*tmp;

	while (infos->next)
	{
		i = -1;
		tmp = infos->content;
		while (tmp[++i] != 'R')
			;
		if (tmp[i] == 'R')
		{
			i = index - 1;
			while (tmp[i++] && (tmp[i] < '0' || tmp[i] > '9'))
				if (tmp[i] == '-')
					return (-1);
			while (tmp[i] && (tmp[i] >= '0' && tmp[i] <= '9'))
				res->y = (res->y * 10) + (tmp[i++] - 48);
			return (res->y);
		}
		infos = infos->next;
	}
	return (0);
}

t_list				*ft_infos_gnl(int fd, t_list **mapinfos)
{
	int			ret;
	t_list		*infos;
	t_list		*map;
	char		*line;

	map = *mapinfos;
	infos = NULL;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (line[0])
		{
			if (!ft_is_map_line(line))
				ft_lstadd_back(&infos, ft_lstnew(ft_strtrim(line, " \t")));
			else
				ft_lstadd_back(&map, ft_lstnew(ft_strdup(line)));
		}
		free(line);
	}
	if (line)
		free(line);
	return (infos);
}

int					ft_get_path(char *to_find, t_list *lst, char **s)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (lst->next)
	{
		if (ft_strncmp(to_find, lst->content, 2) == 0)
		{
			tmp2 = lst->content;
			i = ft_strlen(tmp2);
			while (tmp2[i] != ' ')
				i--;
			if (!(tmp = ft_substr(tmp2, i + 1, ft_strlen(tmp2))))
				return (-1);
			if (!(*s = ft_strdup(tmp)))
				return (-1);
			free(tmp);
			if (*s)
				return (1);
		}
		lst = lst->next;
	}
	return (0);
}

size_t				ft_parseinfos(t_list **list, t_mapinfos **map, int fd, t_list *g)
{
	t_list			*lst_tmp;
	t_mapinfos		*map_tmp;
	int				ret;

	if (!(*map = ft_init_mapinfos(-1, g)))
		return (-3);
	map_tmp = *map;
	if (!(*list = ft_infos_gnl(fd, &map_tmp->map)))
		return (-3);
	lst_tmp = *list;
	if ((ret = ft_get_res_x(lst_tmp, map_tmp->res)) <= 0)
		return (-4);
	if ((ret = ft_get_res_y(lst_tmp, map_tmp->res, ret)) <= 0)
		return (-4);
	if (!(ft_check_path(lst_tmp, map_tmp->text)))
		return (-5);
	ret = ft_get_rgb("F ", lst_tmp, &map_tmp->floor_rgb);
	if (ret < 0 || ft_get_rgb("C ", lst_tmp, &map_tmp->ceil_rgb) < 0)
		return (-6);
	if (!(map_tmp->map_tab = ft_lst_to_tab(map_tmp->map, map_tmp)))
		return (-3);
	if (!(ft_get_start_position(map_tmp, map_tmp->map_tab)))
		return (-7);
	map_tmp->win_h = map_tmp->res->y;
	map_tmp->win_w = map_tmp->res->x;
	return (1);
}
