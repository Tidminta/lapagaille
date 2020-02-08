/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 21:12:52 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/08 19:49:13 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	char	*string;
	int		fd;
	int		i;

	(void)ac;
	i = 0;
	fd = open(av[1], O_RDONLY);
	printf("fd = %d\n", fd);
	string = NULL;
	if (fd == -1)
	{
		ft_putstr("OPEN FAILED\n");
		return (0);
	}
	while (get_next_line(fd, &string) > 0)
	{
		printf("[main]\n");
		ft_putstr(string);
		printf("**********\n");
		free(string);
		string = NULL;
	}
	// system("leaks a.out");
	return (0);
}
