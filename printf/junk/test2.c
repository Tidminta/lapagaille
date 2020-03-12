/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:00:08 by tidminta          #+#    #+#             */
/*   Updated: 2020/03/04 16:25:51 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#include <stdio.h>

size_t		ft_strncopy(char *dst, const char *src, int *start, size_t dstsize)
{
	size_t	j;

	j = 0;
	if (!src || !dst)
		return (0);
	if (dstsize == 0)
		return (*start);
	while (src[*start] && j < dstsize - 1)
	{
		dst[j] = src[*start];
		j++;
		*start += 1;
	}
	dst[j] = '\0';
	return (1);
}

int			ft_get_precis2(const char *s, int *index, t_infos_ *struct_ptr_)
{
	unsigned int	j;
	int				precis;
	char			*alloc;
	size_t			len;

	precis = 0;
	j = *index + 1;
	len = 0;
	alloc = NULL;
	printf("[ft_get_precis2 *index][%d+]\n", *index);
	if ((s[*index] > 0) && (s[*index - 1] == '.'))
	{
		while (s[++(*index)] && ft_isdigit(s[*index])
			&& !(ft_check_conv_spe(s[*index])))
			len++;
		printf("[get_precis 2][len][%lu]\n", len);
		if (len)
		{
			if (!(alloc = ft_substr(s, j, len)))
				return (-1);
		}
		precis = ft_atoi(alloc);
		free(alloc);
		if (ft_check_conv_spe(s[*index]))
			struct_ptr_->conv_spe = s[*index];
	}
	return (precis);
}

int main(void)
{
	int i;
	const char	*str = "paris est %1234.5678d";
	t_infos_ *struct_ptr;

	i = 0;
	struct_ptr = ft_init_struct();
	ft_display_struct(struct_ptr, &i);
	struct_ptr->width = ft_get_width(str, &i);
	ft_display_struct(struct_ptr, &i);
	struct_ptr->precis = ft_get_precis2(str, &i, struct_ptr);
	ft_display_struct(struct_ptr, &i);
	return (0);
}
