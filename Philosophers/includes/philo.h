/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:00:44 by tidminta          #+#    #+#             */
/*   Updated: 2021/09/15 02:17:23 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
#include <sys/time.h>

# include "../libft/libft.h"
// # include "./fct.h"

# define $BR exit(0);

# define ERROR -1
# define SUCCESS 0

typedef unsigned long	T_TIME;

typedef struct	s_lst
{
	int				id;
	struct s_lst	*p;
	struct s_lst	*n;
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
	int		nb;
}				t_data;

/*
**	int gettimeofday(struct timeval *tv, struct timezone *tz);
**
**
*/

typedef struct	s_tools
{
	int		mlc_fail;
	struct timeval *tv;
	struct timezone *tz;
}				t_tools;

typedef struct s_ctrl
{
	t_philo	*philos;
	t_data	*data;
	t_tools	*tools;
}				t_ctrl;

/*
**	INIT
*/

int		init_jobs(t_ctrl *ctrl, char **av);

int		add_one(t_ctrl *ctrl, int id);

int		add_philo(t_ctrl *ctrl, int nb);

int		init_jobs(t_ctrl *ctrl, char **av);

int		add_one(t_ctrl *ctrl, int id);

int		add_philo(t_ctrl *ctrl, int nb);

int		free_philo(t_ctrl *ctrl, int i);

t_ctrl	*init_ctrl(char **av);

/*
**	THREADS
**	int pthread_create(pthread_t * thread, pthread_attr_t * attr, void * (*start_routine)(void *), void * arg);  
*/

int		start_philo(t_ctrl *ctrl);

/*
**	TOOLS
*/

int		is_same(char *s1, char *s2);

void	print_philo(t_ctrl *ctrl, char *mode);

# endif