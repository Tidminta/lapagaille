/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 21:12:52 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/06 03:21:35 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	char	*str;
	int		fd;
	int		i;

	(void)ac;
	i = 0;
	fd = open(av[1], O_RDONLY);
	printf("fd = %d\n", fd);
	str = NULL;
	if (fd == -1)
	{
		ft_putstr("OPEN FAILED\n");
		return (0);
	}
	while (get_next_line(fd, &str) > 0)
	{
		get_next_line(fd, &str);
		ft_putstr(str);
	// get_next_line(fd, &str);
	// ft_putstr(str);
	// get_next_line(fd, &str);
	// ft_putstr(str);
	// get_next_line(fd, &str);
	// get_next_line(fd, &str);
	// ft_putstr(str);
	}
	// system("leaks a.out");
	return (0);
}
