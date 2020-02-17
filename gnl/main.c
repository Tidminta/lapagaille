/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 21:12:52 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/14 15:13:28 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	while ((ret = get_next_line(42, &string)) > 0)
	{
		// printf("\n[main]\n");
		printf("%s\n", string);
		free(string);
		string = NULL;
		// printf("ret = %i\n", ret);
	}
	// printf("[hors boucle]\n");
	printf("%s\n", string);
	free(string);
	string = NULL;
	// printf("dernier return = %i\n", ret);
	// system("leaks a.out");
	return (0);
}
