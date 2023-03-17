/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tminta <tminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:20:27 by motoure           #+#    #+#             */
/*   Updated: 2023/03/16 18:52:45 by tminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*return_value;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 0;
	}
	if (!(return_value = malloc(size * count)))
		return (0);
	ft_memset(return_value, 0, count * size);
	return (return_value);
}
