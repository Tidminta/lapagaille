/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:57:50 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/08 20:25:05 by tidminta         ###   ########.fr       */
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
}

void		ft_print_list(t_list *map)
{
	ft_printf("************ LIST ************\n");
	while (map->next)
	{
		printf("[%s]\n", map->content);
		map = map->next;
	}
	ft_printf("************* END *************\n");
}
