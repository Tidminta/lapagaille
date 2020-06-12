/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:42:32 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/12 16:21:44 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include "includes/libft.h"
#include "mlx/mlx.h"

int		main(int ac, char **av)
{
	int			fd;
	t_list		*list;
	t_mapinfos	*map;
	// void	(*del)(void*) = free;
	void *mlx_ptr;
	void *mlx_win;

	if (ac == 2)
	{
		printf("EXIT\n");
		list = NULL;
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			ft_printf("Error\nMap open failed\n");
			return (0);
		}
		if (!ft_parseinfos(&list, &map, fd))
		{
			ft_printf("Error\nMap parsing failed\n");
			return (0);
		}
		// ft_print_mapinfos(map);
		// ft_lstclear(&list, del);
		// ft_print_list(list);
		close(fd);
		mlx_ptr = mlx_init();
		mlx_win = mlx_new_window(mlx_ptr, 500, 500, "mlx42");
		system("leaks Cub3D");
		mlx_loop(mlx_ptr);
		return (0);
	}
	ft_printf("Error\nInvalide number of arguments!\n");
	return (0);
}
