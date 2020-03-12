/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_args_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:39:56 by tidminta          #+#    #+#             */
/*   Updated: 2020/03/03 15:53:28 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int		*ft_cut(va_list *list_ptr, int nbr, int *index, int *sum)
{
	int tmp;

	while (*index < nbr)
	{
		tmp = va_arg(list_ptr, int);
		printf("argument[%d] = %d\n", *index, tmp);
		sum += tmp;
		*index += 1;
	}
	return (sum);
}

int		ft_sumnum(int nb, ...)
{
	va_list list_ptr;
	int		tmp;
	int		sum;
	int		i;

	sum = 0;
	i = 0;
	va_start(list_ptr, nb);
	while (i < nb)
		sum = ft_cut(list_ptr, nb, &i, &sum);
	va_end(list_ptr);
	return (sum);
}


int main(void)
{
	va_list list_ptr;

	va_start(list_ptr, nb);
	return (0);
}
