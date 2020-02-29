/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:38:52 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/29 22:41:49 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		main(void)
{
	int			i;
	char		*str = "paris %-1234.5678c est magique";
	t_infos_	*struct_ptr;

	i = 0;
	// printf("str [7] = [%c]\n", str[7]);
	struct_ptr = ft_init_struct();
	ft_get_flag(str, &i, struct_ptr);
	struct_ptr->width = ft_get_width(str, &i);
	struct_ptr->precis = ft_get_precis(str, &i);
	printf("[flag zero] = [%d]\n", struct_ptr->flag_zero);
	printf("[flag moins] = [%d]\n", struct_ptr->flag_moins);
	printf("[width] = [%d]\n", struct_ptr->width);
	printf("[precision] = [%d]\n", struct_ptr->precis);
	free(struct_ptr);
	// system("leaks a.out");
	return (0);
}
