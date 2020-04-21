/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 22:30:24 by tidminta          #+#    #+#             */
/*   Updated: 2020/04/20 20:31:45 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_putstr_fd2(char *s, int fd, t_params_ *p)
{
	int len;

	len = 0;
	if (!s || !fd)
	{
		write(1, "(null)", 6);
		p->conv_len += 6;
		return ;
	}
	while (s[len])
		len++;
	write(fd, s, len);
	p->conv_len += len;
}
