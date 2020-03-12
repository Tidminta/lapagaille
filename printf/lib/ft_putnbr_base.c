/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 21:23:13 by tidminta          #+#    #+#             */
/*   Updated: 2020/03/07 22:56:39 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	ft_check_base(char *str)
{
	size_t i;
	size_t j;

	i = 0;
	j = i + 1;
	if (str[0] == '\0')
		return (0);
	if (ft_strlen(str) < 2)
		return (0);
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if ((str[i] == str[j]) || (str[i] == '+' || str[i] == '-') ||
					(str[j] == '-' || str[j] == '+') ||
						(str[i] < 32 || str[i] > 126) ||
							((str[j] < 32 || str[j] > 126)))
				return (0);
			j++;
		}
		i++;
	}
	return (ft_strlen(str));
}

/*
** 3. nb = nbr | b_s = base_size | b = (char *)base | *i = cpt
*/

static void		ft_dothejob(unsigned long n, unsigned int b_s, char *b, t_params_ *p)
{
	if (n < b_s)
	{
		ft_putchar_fd(b[n], 1, p);
	}
	else
	{
		ft_dothejob((n / b_s), b_s, b, p);
		ft_putchar_fd(b[n % b_s], 1, p);
	}
}

void			ft_putnbr_base(unsigned long nbr, char *base, t_params_ *p)
{
	size_t		len_base;

	len_base = ft_check_base(base);
	if (len_base >= 2)
		ft_dothejob(nbr, len_base, base, p);
}
