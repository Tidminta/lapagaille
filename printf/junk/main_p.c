/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 23:08:44 by tidminta          #+#    #+#             */
/*   Updated: 2020/03/17 20:18:50 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libftprintf.h"

int	main(void)
{
	size_t			ret;
	size_t			tmp;
	size_t			len;
	

	ret = ft_strlen("0xffffffff");
	len = 1;
	printf("[len][%lu]\n", ret);
	tmp = 10;
	while (tmp && (tmp/10 > 0))
	{
		tmp /= 10;
		len++;
	}
	printf("[len2][%lu]", len);
	// printf("[hexa long][%#20.10x]\n", 4294967295);
	return (0);
}
