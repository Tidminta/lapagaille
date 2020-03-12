/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 23:08:44 by tidminta          #+#    #+#             */
/*   Updated: 2020/03/12 18:11:03 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libftprintf.h"

int	main(void)
{
	size_t ret;

	ret = ft_strlen("              ");
	printf("ret = %lu\n", ret);
	printf("[test flag zero sans width et sans precision][%0.10d]\n",12345);
	return (0);
}
