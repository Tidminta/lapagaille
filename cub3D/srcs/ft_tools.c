/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:57:50 by tidminta          #+#    #+#             */
/*   Updated: 2020/07/01 19:10:41 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_print_mapinfos(t_mapinfos *map)
{
	ft_printf("************ MAP INFOS ************\n");
	printf("[line max][%zu]\n", map->line_max);
	printf("[res x][%zu]", map->resolution->res_x);
	printf("[res y][%zu]\n", map->resolution->res_y);
	printf("[NO][%s]\n", map->no);
	printf("[SO][%s]\n", map->so);
	printf("[WE][%s]\n", map->we);
	printf("[EA][%s]\n", map->ea);
	printf("[S][%s]\n", map->sprite);
	printf("[F][R][%zu][G][%zu][B][%zu]\n",
		map->floor->red, map->floor->green, map->floor->bleue);
	printf("[C][R][%zu][G][%zu][B][%zu]\n",
		map->ceil->red, map->ceil->green, map->ceil->bleue);
	printf("[START POSITION][%zu][%zu]\n", map->start_y, map->start_x);
	// ft_print_list(map->map);
	ft_print_tab(map->map_tab);
	ft_printf("************* END *************\n");
}

void		ft_print_list(t_list *map)
{
	ft_printf("************ LIST ************\n");
	while (map->next)
	{
		printf("[%s]\n", map->content);
		map = map->next;
	}
	if (map->content)
		printf("[%s]\n", map->content);
	ft_printf("************* END *************\n");
}

void		ft_print_tab(char **tab)
{
	size_t	i;

	i = 0;
	ft_printf("************ TAB  ************\n");
	while (tab[i])
	{
		printf("[%zu][%s]\n", i, tab[i]);
		i++;
	}
}
