/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 03:51:42 by lmarques          #+#    #+#             */
/*   Updated: 2020/06/15 19:00:11 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"
#include <stdlib.h>

int	main(void)
{
	t_mlx	*mlx;
	int		count_w;
	int		count_h;

	count_h = -1;
	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	mlx->img = (t_img*)malloc(sizeof(t_img));
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Puff Tiddy");
	mlx->img->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->img->data = (int *)mlx_get_data_addr(mlx->img->img_ptr, &mlx->img->bpp, &mlx->img->size_l,
		&mlx->img->endian);
	while (++count_h < WIN_HEIGHT)
	{
		count_w = -1;
		while (++count_w < WIN_WIDTH)
		{
			if (count_w % 2)
				mlx->img->data[count_h * WIN_WIDTH + count_w] = 0xFFFFFF;
			else
				mlx->img->data[count_h * WIN_WIDTH + count_w] = 0;
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img->img_ptr, 0, 0);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
