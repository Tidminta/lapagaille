/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:42:32 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/12 16:36:06 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include "includes/libft.h"
#include "mlx/mlx.h"

int		main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;

	if (ac == 2)
	{
		mlx_ptr = mlx_init();
		mlx_win = mlx_new_window(mlx_ptr, 500, 500, "mlx42");
		img = mlx_new_image(mlx_ptr, 1920, 1080);
		mlx_loop(mlx_ptr);
		return (0);
	}
	ft_printf("Error\nInvalide number of arguments!\n");
	return (0);
}
