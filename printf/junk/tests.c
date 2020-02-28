/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:13:08 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/28 23:49:14 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../lib/libft.h"
#include <stdio.h>

int             ft_isdigit(int c)
{
        return (c >= '0' && c <= '9');
}

char		ft_check_conv_spe(char car)
{
	if (car == 'c' || car == 's' || car == 'p' || car == 'd' || car == 'i'
		|| car == 'o' || car == 'u' || car == 'u' || car == 'x' || car == 'X')
		return (car);
	return (0);
}

size_t		ft_strncopy(char **dst, const char *src, int start, size_t dstsize)
{
	size_t	j;
	int k;

	j = 0;
	k = 0;
	if (!src || !dst)
		return (0);
	if (dstsize == 0)
		return (start);
	while (j < dstsize - 1)
	{
		(*dst)[j] = src[start];
		printf("[ft_strncopy][%zu] = [%c]\n", j, *dst[j]);
		j++;
		start += 1;
	}
	(*dst)[j] = '\0';
	return (1);
}

int		main(void)
{
	printf("%-010d", 1234);
	return (0);
}

// int		ft_sumnum(int nb, ...)
// {
// 	va_list list_ptr;
// 	int		sum;
// 	int		i;

// 	sum = 0;
// 	i = 0;
// 	va_start(list_ptr, nb);
// 	while (i < nb)
// 	{
// 		sum += va_arg(list_ptr, int);
// 		i++;
// 	}
// 	va_end(list_ptr);
// 	return (sum);
// }