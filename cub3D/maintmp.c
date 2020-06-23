/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:42:32 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/22 14:52:19 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include "includes/libft.h"
#include "mlx/mlx.h"
#include <math.h>

// while (++count_h < WIN_HEIGHT)
// {
// 	count_w = -1;
// 	while (++count_w < WIN_WIDTH)
// 	{
// 		if (count_w % 2)
// 			mlx->img->data[count_h * WIN_WIDTH + count_w] = 0xFFFFFF;
// 		else
// 			mlx->img->data[count_h * WIN_WIDTH + count_w] = 0;
// 	}
// }


typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		*img;
}				t_mlx;

int			deal_key(int key, t_mlx *mlx)
{
	int		count_w;
	int		count_h;

	count_h = 0;
	count_w = 0;
	if (key == 124)
	{
		ft_printf("[fleche droite]\n");
		count_h = (count_h < 0) ? 0 : count_h;
	}
	else if (key == 125)
	{
		count_w = (count_w < 0) ? 0 : count_w;
		ft_printf("[fleche bas]\n");
	}
	else if (key == 53)
	{
		ft_printf("ECHAP\n");
		mlx_destroy_window(mlx->mlx_ptr, mlx->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int		deal_mouse(int button, int x, int y, void *param)
{
	(void)param;
	if (button)
	{
		ft_printf("[mouse][%i]\n", button);
		ft_printf("[x->%i][y->%i]\n", x, y);
	}
	return (0);
}

int	main(void)
{
	t_mlx	*mlx;
	void	*xpm_img_ptr;
	char	*xmp_path = "./images/test.XPM";
	int		img_width;
	int		img_heigt;

	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	mlx->img = (t_img*)malloc(sizeof(t_img));
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "mlx42");
	mlx->img->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->img->data = (int *)mlx_get_data_addr(mlx->img->img_ptr, &mlx->img->bpp, &mlx->img->size_l, &mlx->img->endian);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, xpm_img_ptr, 0, 0);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
