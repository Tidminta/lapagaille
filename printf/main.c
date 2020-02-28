/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:38:52 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/28 22:59:30 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		main(void)
{
	int i;
	int str_width;
	int	str_precis;

	i = 0;
	str_width = ft_get_width("paris %1234.5678c est magique", &i);
	str_precis = ft_get_precis("paris %1234.5678c est magique", &i);
	printf("width = [%d] i = [%d]\n", str_width, i);
	printf("precis = [%d] i = [%d]\n", str_precis, i);
	// system("leaks a.out");
	return (0);
}
