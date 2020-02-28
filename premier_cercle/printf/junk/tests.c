/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:13:08 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/28 14:56:31 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include <stdio.h>

int			ft_get_width(const char *s, int *index);
char		ft_check_conv_spe(char car);
int			ft_get_width(const char *s, int *index);

int		main(void)
{
	int		i;
	int		str_width;

	i = 0;
	str_width = ft_get_width("paris %15522.15c est magique", &i);
	printf("width = [%d]\ni = [%d]\n", str_width, i);
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