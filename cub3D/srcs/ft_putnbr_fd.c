/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 22:40:24 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/04 18:38:10 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <unistd.h>

void		ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n, fd);
	}
	else if (n >= 0 && n <= 9)
	{
		ft_putchar_fd((n + 48), fd);
	}
	else
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putchar_fd(((n % 10) + 48), fd);
	}
}
