/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 13:00:34 by tidminta          #+#    #+#             */
/*   Updated: 2020/07/01 19:28:05 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

t_mapinfos	*ft_init_mapinfos(void)
{
	t_mapinfos	*map;

	map = (t_mapinfos*)malloc(sizeof(t_mapinfos));
	map->resolution = (t_res*)malloc(sizeof(t_res));
	map->resolution->res_x = 0;
	map->resolution->res_y = 0;
	map->floor = (t_rgb*)malloc(sizeof(t_rgb));
	map->ceil = (t_rgb*)malloc(sizeof(t_rgb));
	map->map = ft_lstnew("");
	map->map_tab = NULL;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->sprite = NULL;
	map->line_max = 0;
	map->col_max = 0;
	map->start_x = 0;
	map->start_y = 0;
	return (map);
}

void			ft_get_rgb(char *to_find, t_list *lst, t_rgb **rgb)
{
	char	**tab;
	char	*str;
	t_rgb	*tmp;

	tmp = *rgb;
	while (lst->next || lst->content)
	{
		str = lst->content;
		if (ft_strncmp(str, to_find, 2) == 0)
		{
			while (ft_isalpha(*str) || *str == ' ')
				str++;
			if (ft_isdigit(*str))
			{
				tab = ft_split(str, ',');
				tmp->red = ft_atoi(tab[0]);
				tmp->green = ft_atoi(tab[1]);
				tmp->bleue = ft_atoi(tab[2]);
				ft_free_split(tab);
			}
		}
		if (lst->next)
			lst = lst->next;
		else
			return ;
	}
}

size_t		ft_is_map_char(char c)
{
	char	*str;
	size_t	i;

	i = 0;
	str = " 012NSEW";
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t		ft_is_map_line(char *s)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	while (ft_is_map_char(s[i]))
		i++;
	if (i == len)
		return (1);
	return (0);
}

char		**ft_lst_to_tab(t_list *lst, t_mapinfos *map)
{
	char	**tab;
	char	*tmp;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_lstsize(lst);
	map->line_max = len;
	tab = (char**)malloc(sizeof(char*) * (len + 1));
	tab[len] = 0;
	while (lst->next)
	{
		tmp = lst->content;
		if (tmp[0])
		{
			if ((len = ft_strlen(tmp)) > map->col_max)
				map->col_max = len;
			tab[i++] = tmp;
		}
		lst = lst->next;
	}
	if (lst->content)
		tab[i] = lst->content;
	return (tab);
}
