/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 23:30:00 by tidminta          #+#    #+#             */
/*   Updated: 2019/12/04 19:00:49 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "libft.h"

void	ft_print_result(int n)
{
	char c;

	if (n >= 10)
		ft_print_result(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int		main(void)
{
	char	*dest;

	if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
		return (0);
	memset(dest, 0, 15);
	memset(dest, 'r', 6);
	// printf("avant %s\n", dest);
	// memset(dest, 'r', 15);
	// printf("apres %s\n", dest);
	// ft_print_result(strlcat(dest, "lorem ipsum dolor sit amet", 5));
	// write(1, "\n", 1);
	// write(1, dest, 15);
	strlcat(dest, "lorem ipsum dolor sit amet", 5);
	printf("%s\n", dest);
	return (0);
}
