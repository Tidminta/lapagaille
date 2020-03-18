/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:28:26 by tidminta          #+#    #+#             */
/*   Updated: 2020/03/18 22:06:19 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libftprintf.h"

int		main(void)
{
	// int				nb;
	// int				nb2;
	// unsigned int	nb3;
	int				ret;
	int				ret2;
	// int				real_ret;
	// unsigned int	hexa;
	// unsigned int	octal;
	// char			c;
	char			*str;
	// void			*p;
	// c = 'z';
	// nb = 2147483647;
	// nb2 = -12345;
	// nb3 = 4294967295;
	// hexa = 4294967295;
	// octal = 0;
	str = "tidiane";
	// p = &str;
	ret = ft_printf("[ft_[string][%-10.10s]", str);
	printf("[%d]\n", ret);
	ret2 = printf("[fct[string][%-10.10s]", str);
	printf("[%d]\n", ret2);
	// ret = ft_printf("[ft_ digit+][%-25.3d]", nb3);
	// printf("[%d]\n", ret);
	// ret2 = printf("[fct digit+][%-25.3d]", nb3);
	// printf("[%d]\n", ret2);
	// printf("[real normal d print][%020.d]", nb2);
	// ret = ft_printf("[integer][Yo! tu est actuellement dans le cluster %i !]\n", nb2);
	// ret = ft_printf("[char][print only %c]\n", c);
	// ret = ft_printf("[string][%s]\n", str);
	// ret = ft_printf("[unsigned int][%u]\n", hexa);
	// ret = ft_printf("[int-hexa][%i] = [%x]\n", nb, nb);
	// ret = ft_printf("[int-heXa][%i] = [%X]\n", nb, nb);
	// printf("[real printf unsigned int-hexa test][%u] = [%X]\n", hexa, hexa);
	// ret = ft_printf("[pointer test 1][%p]\n", p);
	// real_ret = printf("[pointer test 2][%p]\n", p);
	// system("leaks a.out");
	return (0);
}
