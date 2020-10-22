/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 13:00:34 by tidminta          #+#    #+#             */
/*   Updated: 2020/10/22 13:55:41 by tidminta         ###   ########.fr       */
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
			res->x = (res->x > RESO_X_MAX) ? RESO_X_MAX : res->x;
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
		while (tmp[++i] && tmp[i] != 'R')
			;
		if (tmp[i] == 'R')
		{
			i = index - 1;
			while (tmp[i++] && (tmp[i] < '0' || tmp[i] > '9'))
				if (tmp[i] == '-')
					return (-1);
			while (tmp[i] && (tmp[i] >= '0' && tmp[i] <= '9'))
				res->y = (res->y * 10) + (tmp[i++] - 48);
			res->y = (res->y > RESO_Y_MAX) ? RESO_Y_MAX : res->y;
			return (res->y);
		}
		infos = infos->next;
	}
	return (-1);
}

t_list				*ft_infos_gnl(int fd, t_list **mapinfos)
{
	int			ret;
	t_list		*infos;
	char		*line;
	int			cpt;

	infos = NULL;
	cpt = -1;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (line[0])
		{
			if (!ft_is_map_line(line) && ++cpt < 8)
				ft_lstadd_back(&infos, ft_lstnew(ft_strtrim(line, " \t")));
			else
				ft_lstadd_front(mapinfos, ft_lstnew(ft_strdup(line)));
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

size_t				ft_parseinfos(t_list **list, t_mapinfos **map,
					int fd, t_list *g)
{
	int				ret;

	if (!(*map = ft_init_mapinfos(-1, g)))
		return (-1);
	(*map)->fd = fd;
	if (!(*list = ft_infos_gnl(fd, &(*map)->map)))
		ft_error(&(*map)->garbage, "Error\nMalloc error.\n", 0, (*map));
	if ((ret = ft_get_res_x(*list, (*map)->res)) <= 0)
		(*map)->res->x = 0;
	if ((ret = ft_get_res_y(*list, (*map)->res, ret)) <= 0)
		(*map)->res->y = 0;
	if (!(ft_check_path(*list, (*map)->text)))
		ft_error(&(*map)->garbage,
			"Error\nBad path for texture(s)!\n", 0, (*map));
	ret = ft_get_rgb("F ", *list, &(*map)->floor_rgb);
	if (ret < 0 || ft_get_rgb("C ", *list, &(*map)->ceil_rgb) < 0)
		ft_error(&(*map)->garbage, "Error\nBad RGB.\n", 0, (*map));
	if (!((*map)->map_tab = ft_lst_to_tab((*map)->map, (*map), 0)))
		ft_error(&(*map)->garbage, "Error\nMalloc error.\n", 0, (*map));
	if (!(ft_get_start_position((*map), (*map)->map_tab, -1)))
		ft_error(&(*map)->garbage,
		"Error\nBad character(s) or No/multiple player.\n", 0, (*map));
	ft_freelst(*list);
	ft_map_is_closed((*map), (*map)->map_tab, (*map)->res->x);
	return (1);
}
