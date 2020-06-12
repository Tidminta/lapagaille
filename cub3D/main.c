/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:42:32 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/12 16:48:13 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include "includes/libft.h"
#include "mlx/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int		main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_data	img;

	if (ac == 2)
	{
		mlx_ptr = mlx_init();
		mlx_win = mlx_new_window(mlx_ptr, 500, 500, "mlx42");
		img.img = mlx_new_image(mlx_ptr, 1920, 1080);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, img.endian);
		mlx_loop(mlx_ptr);
		return (0);
	}
	ft_printf("Error\nInvalide number of arguments!\n");
	return (0);
}
