/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tminta <tminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:04:36 by tminta            #+#    #+#             */
/*   Updated: 2023/05/13 21:02:26 by tminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe	*box;

	if (argc != 5)
	{
		ft_putstr_fd("Bad number of arguments!\n", 2);
		exit (0);
	}
	ft_parsing_step(&box, argv, envp);
	if (!box)
		exit(0);
	processing(box);
	return (0);
}
