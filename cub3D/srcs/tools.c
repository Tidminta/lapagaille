/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:57:50 by tidminta          #+#    #+#             */
/*   Updated: 2020/08/04 17:20:29 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_print_mapinfos(t_mapinfos *map)
{
	printf("************ MAP INFOS ************\n");
	printf("[line max][%zu]\n", map->line_max);
	printf("[res x][%d]", map->res->x);
	printf("[res y][%d]\n", map->res->y);
	printf("[NO][%s]\n", map->no->path);
	printf("[SO][%s]\n", map->so->path);
	printf("[WE][%s]\n", map->we->path);
	printf("[EA][%s]\n", map->ea->path);
	printf("[S][%s]\n", map->sprite);
	// printf("[F][R][%zu][G][%zu][B][%zu]\n",
	// 	map->floor->red, map->floor->green, map->floor->bleue);
	// printf("[C][R][%zu][G][%zu][B][%zu]\n",
	// 	map->ceil->red, map->ceil->green, map->ceil->bleue);
	ft_print_list(map->map);
	printf("************* END *************\n");
}

void		ft_print_list(t_list *map)
{
	printf("************ LIST ************\n");
	while (map->next)
	{
		printf("[%s]\n", map->content);
		map = map->next;
	}
	if (map->content)
		printf("[%s]\n", map->content);
	printf("************* END *************\n");
}

void		ft_print_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		printf("[%zu][%s]\n", i, tab[i]);
		i++;
	}
}

