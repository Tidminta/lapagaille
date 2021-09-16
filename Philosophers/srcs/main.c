/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:02:21 by tidminta          #+#    #+#             */
/*   Updated: 2021/09/15 02:12:28 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// int	free_philo(t_ctrl *ctrl, int i);

int	start_philo(t_ctrl *ctrl)
{
	
}

int	main(int ac, char **av)
{
	t_ctrl	*ctrl;

	ctrl = NULL;
	if (ac == 5 || ac == 6)
	{
		if (init_jobs(ctrl, av) == ERROR)
		{
			printf("MEMORY ERROR.\nexit.\n");
			exit (0);
		}
		// start_philo(ctrl);
		printf("start philo\n");
	}
	else
		printf("WRONG NUMBER OF ARGS[%d]\n", ac);
	return (0);
}
