/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:48:08 by tidminta          #+#    #+#             */
/*   Updated: 2019/11/18 20:01:31 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int	main(int ac, char **av)
{
	// /* ******************************************************************** */
	// printf("len = %zu\n", ft_strlen("Tidiane"));
	// /* ******************************************************************** */
	// (void)ac;
	// printf("%i\n", ft_atoi(av[1]));
	// /* ******************************************************************** */
	// int	i;

	// i = 0;
	// ft_memset(av[1], 0, 5);
	// printf("ft_memset\n");
	// while (i <= 5)
	// {	
	// 	printf("%c\n", av[1][i]);
	// 	i++;
	// }
	// i = 0;
	// printf("_memset\n");
	// memset(av[2], 0, 5);
	// while (i <= 5)
	// {
	// 	printf("%c\n", av[2][i]);
	// 	i++;
	// }
	// /* ******************************************************************** */
	// printf("ft_bezero\n");
	// ft_bzero(av[1], ft_strlen(av[1]));
	// printf("\n new av[1] %s\n", av[1]);
	// printf("\nbezero\n");
	// bzero(av[2], ft_strlen(av[2]));
	// printf("\nnew av[2] \n%s\n", av[1]);
	// /* ******************************************************************** */
	// printf("ft_memcpy\n");
	// printf("ft_ : %s\n", ft_memcpy(av[1], av[2], 1));
	// printf("memcpy\n");
	// printf("mem : %s\n", memcpy(av[3], av[4], 1));
	// /* ******************************************************************** */
	// (void)ac;
	// printf("mmccpy : %s\n", memccpy(av[1], "zyxwvuzyxwvu", 'v', 150));
	// printf("\n%s\n", av[1]);
	// printf("\nft_mmcpy : %s\n", ft_memccpy(av[2], "zyxwvuzyxwvu", 'v', 150));
	// printf("\n%s\n", av[2]);
	// /* ******************************************************************** */
	//(void)ac;
	//(void)av;
	//printf("memmove");
	//printf("memmove : %s\n", memmove("lorem_ipsum", "lorem ipsum", 8));
	//printf("ft_mmve : %s\n", ft_memmove("lorem ipsum", "lorem ipsum", 8));
	// /* ******************************************************************** */
	// (void)av;
	// (void)ac;
	// printf("%i\n", ft_isalpha(102));
	// /* ******************************************************************** */
	// (void)av;
	// (void)ac;
	// printf("%i\n", ft_isdigit(48));
	// printf("_isdigit : %i\n", isdigit(48));
	// /* ******************************************************************** */
	// (void)av;
	// (void)ac;
	// printf("%i\n", ft_isalnum(48));
	// printf("_isdigit : %i\n", isalnum(48));
	// // /* ******************************************************************** */
	// (void)av;
	// (void)ac;
	// printf("%i\n", ft_isascii(127));
	// printf("real : %i\n", isascii(127));
	// /* ******************************************************************** */
	// (void)av;
	// (void)ac;
	// printf("%i\n", ft_isprint(126));
	// printf("real : %i\n", isprint(127));
	// /* ******************************************************************** */
	// (void)av;
	// (void)ac;
	// printf("%c\n", toupper(97));
	// printf("ft_ :%c\n", ft_toupper(97));
	/* ******************************************************************** */
	/* ******************************************************************** */
	(void)ac;
	printf("str : %s\n", strchr(av[1], 32));
	printf("\nft_ : %s\n", ft_strchr(av[1], 32));
	/* ******************************************************************** */

	return (0);
}
