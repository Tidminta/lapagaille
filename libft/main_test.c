/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 23:30:00 by tidminta          #+#    #+#             */
/*   Updated: 2019/12/02 23:43:28 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

int main(void)
{
	char	src[] = "lorem ipsum dolor sit amet";
	char	*dest;
	char	src2[] = "lorem ipsum dolor sit amet";
	char	*dest2;

	dest = src + 1;
	dest2 = src2 + 1;
	printf("%s\n", dest);
	if (dest != ft_memmove(dest, src, 8))
		write(1, "dest's adress was not returned\n", 31);
	write(1, dest, 22);
	printf("\n%s\n", memmove(dest2, src2,8));
}
