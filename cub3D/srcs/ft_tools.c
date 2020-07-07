/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:57:50 by tidminta          #+#    #+#             */
/*   Updated: 2020/07/07 17:58:31 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_print_mapinfos(t_mapinfos *map)
{
	printf("************ MAP INFOS ************\n");
	printf("[line max][%zu]\n", map->line_max);
	printf("[res x][%zu]", map->resolution->res_x);
	printf("[res y][%zu]\n", map->resolution->res_y);
	printf("[NO][%s]\n", map->no);
	printf("[SO][%s]\n", map->so);
	printf("[WE][%s]\n", map->we);
	printf("[EA][%s]\n", map->ea);
	printf("[S][%s]\n", map->sprite);
	// printf("[F][R][%zu][G][%zu][B][%zu]\n",
		// map->floor->red, map->floor->green, map->floor->bleue);
	// printf("[C][R][%zu][G][%zu][B][%zu]\n",
		// map->ceil->red, map->ceil->green, map->ceil->bleue);
	printf("[FLOOR RGB][%d]\n", map->floor_rgb);
	printf("[CEIL  RGB][%d]\n", map->ceil_rgb);
	printf("[START POSITION][%zu][%zu]\n", map->start_y, map->start_x);
	// ft_print_list(map->map);
	ft_print_tab(map->map_tab);
	printf("[WIN H][%zu]\n", map->win_h);
	printf("[WIN W][%zu]\n", map->win_w);
	printf("************* END *************\n");
}

void		ft_print_playerinfos(t_player *player)
{
	printf("************ RAY INFOS ************\n");
	printf("[posx][%lf]\n", player->posx);
	printf("[posy][%lf]\n", player->posy);
	printf("[dirx][%lf]\n", player->dirx);
	printf("[diry][%lf]\n", player->diry);
	printf("[planex][%lf]\n", player->planx);
	printf("[planey][%lf]\n", player->plany);
	printf("[time][%lf]\n", player->time);
	printf("[oldtime][%lf]\n", player->oldtime);
	printf("[camerax][%lf]\n", player->camx);
	printf("[cameray][%lf]\n", player->camy);
	printf("[raydirx][%lf]\n", player->raydx);
	printf("[raydiry][%lf]\n", player->raydy);
	printf("[sidedistx][%lf]\n", player->sidedx);
	printf("[sidedisty][%lf]\n", player->sidedy);
	printf("[deltadistx][%lf]\n", player->deltadx);
	printf("[deltadisty][%lf]\n", player->deltady);
	printf("[perpwalldist][%lf]\n", player->perpwd);
	printf("[mapx][%d]\n", player->mapx);
	printf("[mapy][%d]\n", player->mapy);
	printf("[stepx][%d]\n", player->stepx);
	printf("[stepy][%d]\n", player->stepy);
	printf("[hit][%d]\n", player->hit);
	printf("[side][%d]\n", player->side);
	printf("[lineheight][%d]\n", player->lineheight);
	printf("[drawstart][%d]\n", player->drawstart);
	printf("[drawend][%d]\n", player->drawend);
	printf("[X][%d]\n", player->x);
	printf("************* END *************\n");
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
