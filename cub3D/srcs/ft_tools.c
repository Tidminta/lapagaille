/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:57:50 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/10 18:44:40 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/libftprintf.h"

void	ft_print_mapinfos(t_mapinfos *map)
{
	ft_printf("************ MAP INFOS ************\n");
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
	ft_print_list(map->map);
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
	while (tab[i])
	{
		printf("[%zu][%s]\n", i, tab[i]);
		i++;
	}
}
