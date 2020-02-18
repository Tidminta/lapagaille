/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 21:12:52 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/18 16:32:17 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// void	ft_putstr(char *str)
// {
// 	int i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	write(1, str, i);
// }

int		main(int ac, char **av)
{
	char	*string;
	int		fd;
	int		ret;

	(void)ac;
	ret = 0;
	fd = open(av[1], O_RDONLY);
	string = NULL;
	// printf("fd = %i\nBUFF_SIZE = %i\n", fd, BUFFER_SIZE);
	if (fd == -1)
	{
		ft_putstr("OPEN FAILED\n");
		return (0);
	}
	// printf("[avant boucle main]\n");
	while ((ret = get_next_line(fd, &string)) > 0)
	{
		printf("[main]\n");
		printf("%s\n", string);
		free(string);
		string = NULL;
		printf("ret = %i\n", ret);
		printf("***************\n");
	}
	printf("[hors boucle]\n");
	printf("[%s+]\n", string);
	if (string)
	{
		free(string);
		string = NULL;
	}
	printf("dernier return = %i\n", ret);
	// system("leaks a.out");
	return (0);
}
