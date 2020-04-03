/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_real_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:39:56 by tidminta          #+#    #+#             */
/*   Updated: 2020/03/09 15:57:14 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libftprintf.h"

int main(void)
{
	int				nb;
	int				nb2;
	int				ret;
	unsigned int	hexa;
	unsigned int	octal;
	char			c;
	char			*str;

	c = 'z';
	nb = 2147483647;
	nb2 = 75;
	hexa = 4294967295;
	octal = 0;
	str = "tidiane";
	ret = printf("[digit][Yo! tu est actuellement dans le cluster %d !]\n", nb2);
	printf("ret = [%i]\n", ret);
	ret = printf("[integer][Yo! tu est actuellement dans le cluster %i !]\n", nb2);
	printf("ret = [%i]\n", ret);
	ret = printf("[char][print only %c]\n", c);
	printf("ret = [%i]\n", ret);
	ret = printf("[string][%s]\n", str);
	printf("ret = [%i]\n", ret);
	ret = printf("[unsigned int][%u]\n", hexa);
	printf("ret = [%i]\n", ret);
	ret = printf("[int-hexa][%i] = [%x]\n", nb, nb);
	printf("ret = [%i]\n", ret);
	ret = printf("[int-heXa][%i] = [%X]\n", nb, nb);
	printf("ret = [%i]\n", ret);
	printf("[real printf unsigned int-hexa test][%u] = [%X]\n", hexa, hexa);
	printf("ret = [%i]\n", ret);
	printf("*************************\n");

	printf ("Characters: %c %c \n", 'a', 65);
	printf ("Decimals: %d %ld\n", 1977, 650000L);
	printf ("Preceding with blanks: %10d \n", 1977);
	printf ("Preceding with zeros: %010d \n", 1977);
	printf ("Some different radices: %d %x %o [%#x] %#o \n", 100, 100, 100, 100, 100);
	printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	printf ("Width trick: %*d \n", 5, 10);
	printf ("%s \n", "A string");
	return (0);
}
