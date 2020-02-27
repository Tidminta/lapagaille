/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:38:52 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/27 20:36:53 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		main(void)
{
	int i;
	int str_width;

	i = 0;
	str_width = ft_get_width("paris %155-22.15c est magique", &i);
	printf("width = %d\n", str_width);
	system("leaks a.out");
	return (0);
}
