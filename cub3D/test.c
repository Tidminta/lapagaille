/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 19:47:24 by tidminta          #+#    #+#             */
/*   Updated: 2020/10/12 19:52:28 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub.h"

size_t				ft_is_map_char(char c)
{
	char	*str;
	size_t	i;

	i = 0;
	str = " 012NSEW";
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t				ft_is_map_line2(char *s)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = strlen(s);
	while ((s[i]) && ft_is_map_char(s[i]))
	{
		i++;
	}
	if (i == len)
		return (1);
	return (0);
}

int					main(int ac, char *av[])
{
	int ret;

	(void)ac;
	ret = ft_is_map_line2(av[1]);
	printf("ret = %d\n", ret);
	return (0);
}
