/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tminta <marvin@42quebec.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:44:47 by tminta            #+#    #+#             */
/*   Updated: 2022/07/07 15:44:55 by tminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill(char *str, int n, int i)
{
	while (n > 0)
	{
		str[i] = '0' + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}

static int	len(long nb, int i)
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

char	*ft_itoa(int n)
{
	int		i;
	char	*alloc;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n != 0)
	{
		i = len((long)n, 0);
		alloc = (char *)malloc(sizeof(char) * (i + 1));
		if (!alloc)
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
