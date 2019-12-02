/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:48:08 by tidminta          #+#    #+#             */
/*   Updated: 2019/12/02 23:25:17 by tidminta         ###   ########.fr       */
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
	// (void)ac;
	// printf("ft_memcpy\n");
	// printf("ft_ : %s\n", ft_memcpy(av[1], av[2], 10));
	// printf("memcpy\n");
	// printf("mem : %s\n", memcpy(av[3], av[4], 10));
	// /* ******************************************************************** */
	// (void)ac;
	// printf("mmccpy : %s\n", memccpy(av[1], "zyxwvutsrqponmlkjihgfedcba", 'r', 20));
	// printf("\nav[1] : %s\n", av[1]);
	// printf("\n*********** \n");
	// printf("\nft_mmcpy : %s\n", ft_memccpy(av[2], "Paris 56789", 115, 5));
	// printf("\nav[2] : %s\n", av[2]);
	/* ******************************************************************** */
	// (void)ac;
	// (void)av;
	// char str[] = "01234 est magique";
	// char str2[] = "01234 est magique";
  	// char string[] = "Paris 56789";
  	// char string2[] = "Paris 56789";
  
  	// printf("mmccpy : %s\n", memccpy(str, string, 32, 5));
  	// printf("\nav[1] : %s\n", str);
  
  	// printf("\n*********** \n");
  
  	// printf("\nft_mmcpy : %s\n", ft_memccpy(str2, string2, 32, 5));
  	// printf("\nav[2] : %s\n", str2);  
	// /* ******************************************************************** */
	(void)ac;
	(void)av;
	printf("fct : %s\n", memmove(av[1], av[2], ft_strlen(av[2])));
	printf("ft_ : %s\n", ft_memmove(av[3], av[4], ft_strlen(av[4])));
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
	// (void)ac;
	// printf("str : %s\n", strchr(av[1], 32));
	// printf("\nft_ : %s\n", ft_strchr(av[1], 32));
	/* ******************************************************************** */
	//  (void)ac;
	//  (void)av;
	//  printf("str : %s\n", strrchr("", 32));
	//  printf("\nft_ : %s\n", ft_strrchr("", 32));
	/* ******************************************************************** */
	// (void)ac;
	// printf("%i\n", strncmp(av[1], av[2], 5));
	// printf("\nft_ : %i\n", ft_strncmp(av[1], av[2], 5));
	/* ******************************************************************** */
	// (void)ac;
	// printf("%lu\nav[1] : %s\nav[2] : %s\n", strlcpy(av[1], av[2], 17), av[1], av[2]);
	// printf("ft_ : %zi\nav[3] : %s\nav[4] : %s\n", ft_strlcpy(av[3], av[4], 17), av[3], av[4]);
	/* ******************************************************************** */
	// (void)ac;
	// printf("ft_ : %s\n", ft_memchr(av[1], 32, 0));
	// printf("fct : %s\n", memchr(av[1], 32, 0));
	/* ******************************************************************** */
	// (void)ac;
	// printf("ft_ : %i\n", ft_memcmp(av[1], av[2], ft_strlen(av[1])));
	// printf("fct : %i\n", memcmp(av[1], av[2], ft_strlen(av[1])));
	/* ******************************************************************** */

	return (0);
}
