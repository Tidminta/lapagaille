/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:02:21 by tidminta          #+#    #+#             */
/*   Updated: 2021/09/14 17:51:53 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_philo(t_ctrl *ctrl, char *mode)
{
	t_lst *lst;

	lst = NULL;
	if (mode == NULL || (mode != NULL && is_same(mode, "PHILO")))
	{
		printf("\n**	PHILOS	**\n");
		lst = ctrl->philos->head;
		while (lst)
		{
			printf("[PHILO %d]\n", lst->id);
			lst = lst->n;
		}
	}
	if (mode == NULL || (mode != NULL && is_same(mode, "DATA")))
	{
		printf("\n**	DATA	**\n");
		printf("[TIME TO EAT : %li]\n", ctrl->data->eat);
		printf("[TIME TO SLEEP : %li]\n", ctrl->data->sleep);
		printf("[TIME TO DIE : %li]\n", ctrl->data->die);
	}
	else
		printf("MODE NOT SELECTED WELL.\n[PHILO OR DATA]\n");
}

int	free_philo(t_ctrl *ctrl, int i);

int	start_philo(t_ctrl *ctrl);

int	add_philo(t_ctrl *ctrl, int nb);

t_ctrl	*init_ctrl(int ac, char **av)
{
	t_ctrl	*ctrl;

	ctrl = (t_ctrl*)malloc(sizeof(t_ctrl));
	if (!ctrl || ctrl == NULL)
		return (NULL);
	ctrl->philos = (t_philo*)malloc(sizeof(t_philo));
	if (!ctrl->philos || ctrl->philos == NULL)
		return (NULL);
	ctrl->data = (t_data*)malloc(sizeof(t_data));
	if (!ctrl->data || ctrl->data == NULL)
		return (NULL);
	ctrl->philos->head = NULL;
	ctrl->philos->tail = NULL;
	ctrl->data->die = (T_TIME)ft_atoi(av[2]);
	ctrl->data->eat = (T_TIME)ft_atoi(av[3]);
	ctrl->data->sleep = (T_TIME)ft_atoi(av[4]);
	if (av[5])
		ctrl->data->each = ft_atoi(av[5]);
	else
		ctrl->data->each = ERROR;
}

/*
**	checker [ac, av] et nombre de thread max
**	avant init control
*/
int	init_jobs(t_ctrl *ctrl, int nb_philo, char **av)
{
	int i;
	int	ret;

	i = -1;
	ret = 0;
	ctrl = init_ctrl(nb_philo, av);
	print_philo(ctrl, NULL);
	if (!ctrl || ctrl == NULL)
		return (0);
	while (++i < nb_philo)
	{
		ret = add_philo(ctrl, nb_philo);
		if (ret < 0)
		{
			printf("PHILO NUMBER %s INIT FAILED\n", i);
			free_philo(ctrl, i);
		}
	}
}

int	main(int ac, char **av)
{
	t_ctrl	*ctrl;

	ctrl = NULL;
	if (ac == 5 || ac == 6)
	{
		if (!init_jobs(ctrl, ac, av))
		{
			printf("MEMORY ERROR\nexit.\n");
			exit (0);
		}
		start_philo(ctrl);
	}
	else
		printf("WRONG NUMBER OF ARGS(%d)\n");
	return (0);
}