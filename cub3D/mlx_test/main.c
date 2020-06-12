/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 15:19:50 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/12 16:10:53 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>

int	main(void)
{
	void *mlx_ptr;
	void *mlx_win;

	mlx_ptr = mlx_init();
	printf("SUCCES\n");
	mlx_win = mlx_new_window(mlx_ptr, 500, 500, "mlx42");
	mlx_loop(mlx_ptr);
	return (0);
}
