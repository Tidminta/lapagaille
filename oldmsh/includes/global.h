/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:15:27 by tidminta          #+#    #+#             */
/*   Updated: 2021/06/29 20:55:06 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# define GET 0
# define SET 1

/*
** LOOP 0 = 0 PROBLEMES 
*/
# define LOOP 0
# define RELOOP 1


int         g_interrupt(int mode, int value);

int         g_loop(int mode, int value);

#endif