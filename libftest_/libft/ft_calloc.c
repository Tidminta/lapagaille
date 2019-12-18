/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:31:05 by tidminta          #+#    #+#             */
/*   Updated: 2019/12/18 20:21:53 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc;

	count = (count <= 0) ? 1 : count;
	if (!(alloc = malloc(sizeof(size) * count)))
		return (NULL);
	ft_bzero(alloc, count);
	return (alloc);
}
