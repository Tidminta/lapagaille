/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:38:52 by tidminta          #+#    #+#             */
/*   Updated: 2020/03/04 14:27:24 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		main(void)
{
	printf("[debut main]\n");
	int			i;
	// char		*str = "paris %-1234.5678c est magique";
	// t_infos_	*struct_ptr;

	i = 1970;
	printf("[main avant printf]\n");
	ft_printf("paris %d", i);
	printf("[main apres printf]\n");
	// printf("str [7] = [%c]\n", str[7]);
	// struct_ptr = ft_init_struct();
	// ft_get_flag(str, &i, struct_ptr);
	// struct_ptr->width = ft_get_width(str, &i);
	// struct_ptr->precis = ft_get_precis(str, &i, struct_ptr);
	// printf("[flag zero] = [%d]\n", struct_ptr->flag_zero);
	// printf("[flag moins] = [%d]\n", struct_ptr->flag_moins);
	// printf("[width] = [%d]\n", struct_ptr->width);
	// printf("[precision] = [%d]\n", struct_ptr->precis);
	// printf("[conv_spe] = [%c]", struct_ptr->conv_spe);
	// free(struct_ptr);
	// system("leaks a.out");
	return (0);
}
