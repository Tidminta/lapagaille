/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 02:06:59 by tidminta          #+#    #+#             */
/*   Updated: 2021/09/15 02:11:08 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_ctrl	*init_ctrl(char **av)
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
	ctrl->tools = (t_tools*)malloc(sizeof(t_tools));
	if (!ctrl->tools || ctrl->tools == NULL)
		return (NULL);
	ctrl->philos->head = NULL;
	ctrl->philos->tail = NULL;
	ctrl->data->nb = atoi(av[1]);
	ctrl->data->die = (T_TIME)ft_atoi(av[2]);
	ctrl->data->eat = (T_TIME)ft_atoi(av[3]);
	ctrl->data->sleep = (T_TIME)ft_atoi(av[4]);
	if (av[5])
		ctrl->data->each = ft_atoi(av[5]);
	else
		ctrl->data->each = ERROR;
	ctrl->tools->mlc_fail = 0;
	return (ctrl);
}

int	add_one(t_ctrl *ctrl, int id)
{
	t_lst *node;

	node = (t_lst*)malloc(sizeof(t_lst));
	if (!node || node == NULL)
		return (ERROR);
	node->id = id;
	node->n = NULL;
	if (!ctrl->philos->head || ctrl->philos->head == NULL)
	{
		node->p = NULL;
		ctrl->philos->head = node;
		ctrl->philos->tail = node;
	}
	else
	{
		node->p = ctrl->philos->tail;
		ctrl->philos->tail->n = node;
		ctrl->philos->tail = node;
	}
	return (SUCCESS);
}

int	add_philo(t_ctrl *ctrl, int nb)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	if (!ctrl || ctrl == NULL)
		return (0);
	while (++i <= nb)
	{
		ret = add_one(ctrl, i);
		if (ret == ERROR)
		{
			printf("YOU'LL HAVE TO FREE SOME PHILOS ...\n");
			// free_philo(ctrl, i);
		}
	}
	return (SUCCESS);
}

/*
**	checker [ac, av] et nombre de thread max
**	avant init control
*/
int	init_jobs(t_ctrl *ctrl, char **av)
{
	int i;
	int	ret;

	i = -1;
	ret = 0;
	ctrl = init_ctrl(av);
	if (!ctrl || ctrl == NULL)
	{
		printf("L110\n");
		return (ERROR);
	}
	add_philo(ctrl, ctrl->data->nb);
	print_philo(ctrl, NULL);
	if (!ctrl->philos->head || ctrl->philos->head == NULL)
	{
		printf("PHILO NUMBER %d INIT FAILED[FREE PHILO]\n", i);
		// free_philo(ctrl, i);
		return (ERROR);
	}
	return (SUCCESS);
}
