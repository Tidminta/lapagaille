/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:00:08 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/27 20:38:36 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_get_width(const char *s, int *index)//cas d'erreur a gerer !
{
	int				width;
	char			*alloc;
	unsigned int	j;
	size_t			len;

	width = 0;
	len = 0;
	alloc = NULL;
	while (s[*index] && s[*index] != '%')
		*index += 1;
	if (s[*index] == '%')
	{
		j = *index + 1;
		while (s[++(*index)] && ft_isdigit(s[*index])
			&& (ft_isalpha(s[*index]) == 0))
			len++;
		if (!ft_isdigit(s[*index]))
			return (-1);
		if (!(alloc = ft_substr(s, j, len)))
			return (0);
		width = ft_atoi(alloc);
		free(alloc);
		return (width);
	}
	return (0);
}
