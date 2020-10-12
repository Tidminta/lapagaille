/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 12:34:00 by tidminta          #+#    #+#             */
/*   Updated: 2020/10/12 17:58:10 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int				main(int ac, char **av)
{
	t_list		*garbage;
	t_list		*list;
	t_mapinfos	*map;
	t_mlx		*mlx;
	int			fd;

	if (ac == 2)
	{
		list = NULL;
		mlx = NULL;
		if (!(garbage = ft_lstnew("")))
			return (0);
		if ((fd = ft_parse_open(av, &map, &list, &garbage)) < 0)
			return (0);
		ft_print_tab(map->map_tab);
	}
	return (0);
}
