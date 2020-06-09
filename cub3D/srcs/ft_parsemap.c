/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 13:00:34 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/09 18:17:02 by tidminta         ###   ########.fr       */
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

size_t		ft_get_res_y(t_list *infos, t_res *res)
{
	size_t	len;
	size_t	i;
	char	*tmp;
	char	*tmp2;

	while (infos->next)
	{
		tmp = infos->content;
		if (tmp[0] == 'R')
		{
			len = ft_strlen(tmp);
			i = len + 1;
			while ((tmp[--i] < '0' || tmp[i] > '9'))
				;
			while ((tmp[i--] >= '0' && tmp[i] <= '9'))
				;
			tmp2 = ft_substr(tmp, i + 1, len - i);
			res->res_y = ft_atoi(tmp2);
			free(tmp2);
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
	char		*line;

	map = NULL;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (line[0])
		{
			ft_lstadd_back(&map, ft_lstnew(ft_strdup(line)));
		}
		free(line);
	}
	if (line)
		free(line);
	return (map);
}

void		ft_free_tab(char ***tab)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = *tab;
	while (tab[i])
	{
		// free(tab[i]);
		i++;
	}
}

size_t		ft_get_path(char *to_find, t_list *lst, char **s)
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
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}

size_t		ft_parsemap(t_list **list, t_mapinfos **map, int fd)
{
	t_list		*lst_tmp;
	t_mapinfos	*map_tmp;

	map_tmp = *map;
	*list = ft_map_gnl(fd);
	lst_tmp = *list;
	map_tmp->resolution = (t_res*)malloc(sizeof(t_res));
	ft_get_res_x(lst_tmp, map_tmp->resolution);
	ft_get_res_y(lst_tmp, map_tmp->resolution);
	ft_get_path("NO", lst_tmp, &map_tmp->no);
	ft_get_path("SO", lst_tmp, &map_tmp->so);
	ft_get_path("WE", lst_tmp, &map_tmp->we);
	ft_get_path("EA", lst_tmp, &map_tmp->ea);
	ft_get_path("S ", lst_tmp, &map_tmp->sprite);
	ft_print_mapinfos(map_tmp);
	// map_tmp->floor = (t_rgb*)malloc(sizeof(t_rgb));
	// map_tmp->ceil = (t_rgb*)malloc(sizeof(t_rgb));
	return (1);
}
