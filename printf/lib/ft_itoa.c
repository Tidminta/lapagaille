/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 18:56:26 by tidminta          #+#    #+#             */
/*   Updated: 2020/03/06 17:25:35 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*fill(char *str, int n, int i)
{
	while (n > 0)
	{
		str[i] = '0' + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}

static int		len(long nb, int i)
{
	if (nb < 0)
	{
		i = 1;
		nb = nb * -1;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*alloc;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n != 0)
	{
		i = len((long)n, 0);
		if (!(alloc = (char *)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		alloc[i] = '\0';
		i--;
	}
	else
		return (ft_strdup("0"));
	if (n < 0)
	{
		alloc[0] = '-';
		n = n * -1;
	}
	alloc = fill(alloc, n, i);
	return (alloc);
}
