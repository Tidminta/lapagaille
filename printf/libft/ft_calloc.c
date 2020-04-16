/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:31:05 by tidminta          #+#    #+#             */
/*   Updated: 2020/03/06 17:24:42 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (!(alloc = (void *)malloc(size * count)))
		return (NULL);
	ft_bzero(alloc, count * size);
	return (alloc);
}
