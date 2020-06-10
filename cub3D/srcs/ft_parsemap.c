/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 13:00:34 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/10 16:32:45 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/libftprintf.h"

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
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->sprite = NULL;
	return (map);
}

void			ft_get_rgb(char *to_find, t_list *lst, t_rgb **rgb)
{
	char	**tab;
	char	*str;
	t_rgb	*tmp;

	tmp = *rgb;
	while (lst->next)
	{
		str = lst->content;
		if (ft_strncmp(str, to_find, 2) == 0)
		{
			while (ft_isalpha(*str) || *str == ' ')
				(*str)++;
			if (ft_isdigit(*str))
			{
				tab = ft_split(str, ',');
				printf("tab[0][%s] tab[1][%s] tab[2][%s]\n", tab[0], tab[1], tab[2]);
				tmp->red = ft_atoi(tab[0]);
				tmp->green = ft_atoi(tab[1]);
				tmp->bleue = ft_atoi(tab[2]);
				free(tab);
			}
		}
		lst = lst->next;
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

	i = 0;
	while (ft_is_map_char(s[i]))
		i++;
	if (i == ft_strlen(s))
		return (1);
	return (0);
}
