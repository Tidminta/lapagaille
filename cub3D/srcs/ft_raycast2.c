/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 14:08:59 by tidminta          #+#    #+#             */
/*   Updated: 2020/07/14 19:28:58 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		ft_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int			ft_deal_key(int key, t_mlx *mlx)
{
	int		count_w;
	int		count_h;

	count_h = 0;
	count_w = 0;
	if (key == 124)
		ft_printf("[fleche droite]\n");
	else if (key == 125)
		ft_printf("[fleche bas]\n");
	else if (key == 53)
	{
		ft_printf("ECHAP\n");
		mlx_destroy_window(mlx->mlx_p, mlx->win);
		exit(EXIT_SUCCESS);
	}
	else
		printf("[KEY][%d]\n", key);
	return (0);
}
