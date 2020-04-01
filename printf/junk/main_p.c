/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 23:08:44 by tidminta          #+#    #+#             */
/*   Updated: 2020/04/01 14:29:36 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libftprintf.h"

int	main(void)
{
	// t_params_		*p;
	size_t			ret;
	size_t			ret2;
	size_t			ret3;
	unsigned int	ret4;
	size_t			tmp;
	// unsigned char char_spe;

/*
**	*******************************
**			PRINTF TESTS
**	*******************************
*/
	ret4 = 0;
	ret = ft_printf("[ft_][%.s]", "hello");
	printf("[%lu]\n", ret);
	ret2 = printf("[fct][%.s]", "hello");
	printf("[%lu]\n", ret2);
/*
**	*******************************
**			OTHERS
**	*******************************
*/
	ret4 = 42949672;
	ret3 = ret4;
	tmp = (ret3 >= 0) ? 1 : 2;
	ret3 = (ret4 < 0) ? -ret4 : ret4;
	while(ret3 && (ret3/10) > 0)
	{
		ret3 /= 10;
		tmp++;
	}
	// printf("[TMP][%lu]\n[LEN][%lu]\n", tmp, ft_strlen("   "));
	return (0);
}
