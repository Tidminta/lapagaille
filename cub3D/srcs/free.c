/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 16:50:53 by tidminta          #+#    #+#             */
/*   Updated: 2020/10/07 18:58:08 by tidminta         ###   ########.fr       */
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

// void			ft_error(t_mapinfos *map, int indice)
// {
// 	if (indice == -1)
// 	{
// 		printf("Error\nMap file open failed\n");
// 		exit(EXIT_SUCCESS);
// 	}
// 	else if (indice == -2)
// 	{
// 		printf("Error\nMap parsing failed\n");
// 		free (map);
// 	}
// }
