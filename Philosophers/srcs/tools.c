/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 20:53:54 by tidminta          #+#    #+#             */
/*   Updated: 2021/09/15 00:59:47 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_same(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2 || ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[i] && s1[i] == s2[i])
		i++;
	if (s1[i])
		return (0);
	return (1);
}

void	print_philo(t_ctrl *ctrl, char *mode)
{
	t_lst *ph;

	ph = NULL;
	if (mode == NULL || (mode != NULL && is_same(mode, "PHILO")))
	{
		printf("\n**	PHILOS	**\n");
		ph = ctrl->philos->head;
		while (ph)
		{
			printf("[PHILO %d]\n", ph->id);
			ph = ph->n;
		}
	}
	if (mode == NULL || (mode != NULL && is_same(mode, "DATA")))
	{
		printf("\n**	DATA	**\n");
		printf("[NUMBER OF PHILOS : %d]\n", ctrl->data->nb);
		printf("[TIME TO DIE : %li]\n", ctrl->data->die);
		printf("[TIME TO EAT : %li]\n", ctrl->data->eat);
		printf("[TIME TO SLEEP : %li]\n", ctrl->data->sleep);
	}
	else
		printf("MODE NOT WELL SELECTED.\n[PHILO OR DATA]\n");
}
