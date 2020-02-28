/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:38:52 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/28 14:58:01 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		main(void)
{
	int i;
	int str_width;

	i = 0;
	str_width = ft_get_width("paris %15522.15c est magique", &i);
	printf("width = [%d]\ni = [%d]\n", str_width, i);
	printf("len = %zi\n", ft_strlen("18446744073709551615"));
	// system("leaks a.out");
	return (0);
}
