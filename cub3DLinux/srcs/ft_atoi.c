/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:32:37 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/04 18:36:35 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_atoi(const char *str)
{
	int					signe;
	unsigned long		nb;

	signe = 1;
	nb = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		signe = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (nb >= 2147483647)
		{
			if (signe == -1)
				return (0);
			else
				return (-1);
		}
		nb = nb * 10 + (*str - '0');
		str++;
	}
	return ((int)nb * signe);
}
