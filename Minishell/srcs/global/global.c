/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:44:39 by tidminta          #+#    #+#             */
/*   Updated: 2021/06/29 20:57:47 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

// int         g_interrupt(int mode, int value)
// {
//     static int  interruption;

//     if (mode == 1)
//         interruption = value;
//     return (interruption);
// }

int         g_loop(int mode, int value)
{
    static int loop;

    if (mode == SET)
        loop = value;
    return (loop);
}