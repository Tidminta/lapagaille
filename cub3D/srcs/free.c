/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 16:50:53 by tidminta          #+#    #+#             */
/*   Updated: 2020/10/08 18:39:10 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int				ft_free(t_mapinfos *map)
{
	//manque free(sprites)
	free(map->mlx);
	free(map->p);
	free(map->res);
	free(map->map);
	exit(EXIT_SUCCESS);
}

void			ft_free_split(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

/*
**************************************
**		DONT FORGET TO FREE			**
**		zbuff (init.c | l123)		**
**************************************
*/

int			ft_error(t_mapinfos *map, int indice)
{
	(void)map;
	if (indice == -1)
		printf("Error\nMap file open failed\n");
	else if (indice == -2)
		printf("Error\nMap parsing failed\n");
	else if (indice == -3)
		printf("Error\nIt's may be a malloc error\n");
	else if (indice == -4)
		printf("Error\nbad resolution\n");
	else if (indice == -5)
		printf("Error\nBad path for textures or sprite\n");
	else if (indice == -6)
		printf("Error\nBad RGB\n");
	else if (indice == -7)
		printf("Error\nNo/multiple player\n");
	exit(EXIT_SUCCESS);
}
