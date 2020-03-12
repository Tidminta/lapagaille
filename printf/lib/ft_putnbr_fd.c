/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 22:40:24 by tidminta          #+#    #+#             */
/*   Updated: 2020/03/11 17:13:01 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_putnbr_fd(int n, int fd, t_params_ *p)
{
	if (n == -2147483648)
	{
		// ft_putchar_fd('-', fd, p);
		ft_putchar_fd('2', fd, p);
		ft_putnbr_fd(147483648, fd, p);
	}
	else if (n < 0)
	{
		n = -n;
		// ft_putchar_fd('-', fd, p);
		ft_putnbr_fd(n, fd, p);
	}
	else if (n >= 0 && n <= 9)
	{
		ft_putchar_fd((n + 48), fd, p);
	}
	else
	{
		ft_putnbr_fd((n / 10), fd, p);
		ft_putchar_fd(((n % 10) + 48), fd, p);
	}
}
