/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:47:07 by tidminta          #+#    #+#             */
/*   Updated: 2021/09/14 17:51:15 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include "./philo.h"

int	add_philo(t_ctrl *ctrl);

int	free_philo(t_ctrl *ctrl, int i);

#endif