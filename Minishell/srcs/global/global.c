/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:44:39 by tidminta          #+#    #+#             */
/*   Updated: 2021/05/26 15:49:22 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int         g_doublon(int mode, int value)
{
    static int  doublon;

    if (mode == 1)
        doublon = value;
    return (doublon);
}