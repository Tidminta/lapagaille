/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsemap2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 13:00:34 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/10 16:19:53 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/libftprintf.h"

void		ft_get_res_x(t_list *infos, t_res *res)
{
	char		*tmp;
	char		*tmp2;
	size_t		i;
	size_t		j;

	while (infos->next)
	{
		i = -1;
		j = -1;
		tmp = infos->content;
		while (tmp[++i] != 'R')
			;
		if (tmp[i] == 'R')
		{
			while ((tmp[++i] < '0' || tmp[i] > '9'))
				;
			while ((tmp[i + (++j)] >= '0' && tmp[i + j] <= '9'))
				;
			tmp2 = ft_substr(tmp, i, j);
			res->res_x = ft_atoi(tmp2);
			free(tmp2);
			return ;
		}
		infos = infos->next;
	}
}

void		ft_get_res_y(t_list *infos, t_res *res)
{
	size_t	len;
	size_t	i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (infos->next)
	{
		tmp = infos->content;
		len = ft_strlen(tmp);
		if (tmp[i] == 'R')
		{
			i = ft_strlen(tmp);
			while (tmp[i--] && (tmp[i] == ' ' || tmp[i] != '\t'))
				;
			while (tmp[i--] && (tmp[i] >= '0' && tmp[i] <= '9'))
				;
			tmp2 = ft_substr(tmp, i + 1, ft_strlen(tmp) - i);
			res->res_y = ft_atoi(tmp2);
			free(tmp2);
			return ;
		}
		infos = infos->next;
	}
}

t_list		*ft_infos_gnl(int fd, t_list **mapinfos)
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

void		ft_get_path(char *to_find, t_list *lst, char **s)
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
			{
				i--;
			}
			tmp = ft_substr(tmp2, i + 1, ft_strlen(tmp2));
			*s = ft_strdup(tmp);
			free(tmp);
			return ;
		}
		lst = lst->next;
	}
}

size_t		ft_parseinfos(t_list **list, t_mapinfos **map, int fd)
{
	t_list		*lst_tmp;
	t_mapinfos	*map_tmp;

	*map = ft_init_mapinfos();
	map_tmp = *map;
	*list = ft_infos_gnl(fd, &map_tmp->map);
	// ft_print_list(map_tmp->map);
	lst_tmp = *list;
	ft_print_list(lst_tmp);
	ft_get_res_x(lst_tmp, map_tmp->resolution);
	ft_get_res_y(lst_tmp, map_tmp->resolution);
	ft_get_path("NO", lst_tmp, &map_tmp->no);
	ft_get_path("SO", lst_tmp, &map_tmp->so);
	ft_get_path("WE", lst_tmp, &map_tmp->we);
	ft_get_path("EA", lst_tmp, &map_tmp->ea);
	ft_get_path("S ", lst_tmp, &map_tmp->sprite);
	ft_get_rgb("F ", lst_tmp, &map_tmp->floor);
	// ft_print_mapinfos(*map);
	return (1);
}
