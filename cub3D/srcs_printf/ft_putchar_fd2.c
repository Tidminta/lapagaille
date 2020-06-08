/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 22:25:53 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/04 18:57:09 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		ft_putchar_fd2(char c, int fd, t_params_ *p)
{
	write(fd, &c, 1);
	p->conv_len += 1;
}
