/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 17:22:19 by tidminta          #+#    #+#             */
/*   Updated: 2020/03/18 18:05:04 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** *****************************************************************************
**                FONCTION D'AFFICHAGE DES DIFFERENTS CAS DU %c 
**  No precision | [%19.c] ==> [%19c]
**  No 0 flag
**  No # flag
**  width | flag moins
**  SEMBLE FONCTIONNEL
** ******************************************************************************
*/

void        ft_printf_char(t_infos_ *st_, t_params_ *p)
{
    size_t  len;
    
    len = (size_t)st_->width;
    if((!st_->precis && !st_->flag_zero) && !st_->flag_moins)
    {
        while (len-- > 1)
            ft_putchar_fd(' ', 1, p);
        ft_putchar_fd(st_->arg_char, 1, p);
    }
    else if ((!st_->precis && !st_->flag_zero) && st_->flag_moins)
    {
        ft_putchar_fd(st_->arg_char, 1, p);
        while (len-- > 1)
            ft_putchar_fd(' ',1 ,p);
    }
}