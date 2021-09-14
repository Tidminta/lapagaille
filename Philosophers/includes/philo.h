/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:00:44 by tidminta          #+#    #+#             */
/*   Updated: 2021/09/14 17:58:13 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// # include "proto.h"
# include <pthread.h>
# include <stdio.h>

# define ERROR -1
# define SUCCESS 1

typedef unsigned long	T_TIME;

typedef struct	s_lst
{
	int	id;
	struct s_philo *p;
	struct s_philo *n;
}				t_lst;

typedef struct s_philo
{
	t_lst	*head;
	t_lst	*tail;
}				t_philo;

typedef struct s_data
{
	T_TIME	eat;
	T_TIME	die;
	T_TIME	sleep;
	long	each;
}				t_data;

typedef struct s_ctrl
{
	t_philo	*philos;
	t_data	*data;
	
}				t_ctrl;
# endif