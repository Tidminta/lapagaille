/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 18:56:26 by tidminta          #+#    #+#             */
/*   Updated: 2020/01/14 01:57:47 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char				*tab;
	unsigned int		cpt;
	unsigned int		tmp;

	tmp = (n < 0) ? -n : n;
	cpt = (n < 0) ? 2 : 1;
	while ((tmp > 0) && (tmp / 10) > 0)
	{
		cpt++;
		tmp /= 10;
	}
	if (!(tab = ft_calloc((cpt + 1), sizeof(char))))
		return (NULL);
	tmp = (n < 0) ? -n : n;
	if (n < 0)
		tab[0] = '-';
	while (((--cpt) >= 1) && (tmp > 0) && (tmp / 10) > 0)
	{
		tab[cpt] = (tmp % 10) + 48;
		tmp /= 10;
	}
	tab[cpt] = (tmp % 10) + 48;
	return (tab);
}
