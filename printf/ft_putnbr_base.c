/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 21:23:13 by tidminta          #+#    #+#             */
/*   Updated: 2020/04/20 20:25:53 by tidminta         ###   ########.fr       */
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

static void		ft_do(unsigned long n, unsigned int b_s, char *b, t_params_ *p)
{
	if (n < b_s)
	{
		ft_putchar_fd2(b[n], 1, p);
	}
	else
	{
		ft_do((n / b_s), b_s, b, p);
		ft_putchar_fd2(b[n % b_s], 1, p);
	}
}

void			ft_putnbr_base(unsigned long nbr, char *base, t_params_ *p)
{
	size_t		len_base;

	len_base = ft_check_base(base);
	if (len_base >= 2)
		ft_do(nbr, len_base, base, p);
}
