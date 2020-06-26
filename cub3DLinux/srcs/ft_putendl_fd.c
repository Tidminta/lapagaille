/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 22:35:25 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/04 18:38:06 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <unistd.h>

void		ft_putendl_fd(char *s, int fd)
{
	if (!s || !fd)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
	return ;
}
