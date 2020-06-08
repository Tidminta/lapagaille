/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:42:32 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/05 17:37:56 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include "includes/libft.h"

int main(int ac, char **av)
{
	int		fd;
	t_list	*map;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			ft_printf("Error\nMap open failed\n");
			return (0);
		}
		if (!(map = ft_parsemap(fd)))
		{
			ft_printf("Error\nMap parsing failed\n");
			return (0);
		}
		ft_print_list(map);
		return (0);
	}
	ft_printf("Error\nInvalide number of arguments!\n");
	return (0);
}
