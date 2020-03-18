/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 18:05:27 by tidminta          #+#    #+#             */
/*   Updated: 2020/03/18 22:05:38 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** *****************************************************************************
**                FONCTION D'AFFICHAGE DES DIFFERENTS CAS DU %c 
**  width | flag moins | precision
**  (precision)
**      si (precis < len) -> precis donne le nombre de char a afficher
**      sinnon affichage normal
**  No flag 0 | No flag #
** ******************************************************************************
*/

void        ft_printf_string(t_infos_ *st_, t_params_ *p)
{
    size_t  len;
    size_t  len2;
    size_t  indic;
    size_t  i;

/*
** ************************************************
**                  NO FLAG -
** ************************************************
*/
    if (!st_->flag_moins)
    {
        len = ft_strlen(st_->arg_str);
        indic = 0;
        if (st_->width)
        {
            i = -1;
            if (!st_->precis && st_->is_precis == 1)
            {
                while (++i < (size_t)st_->width)
                    ft_putchar_fd(' ', 1, p);
                    indic = 1;
            }
            else if (!st_->precis)
            {
                len = ft_strlen(st_->arg_str);
                while (len++ < (size_t)st_->width)
                    ft_putchar_fd(' ', 1, p);
            }
            else
            {
                if ((len < (size_t)st_->precis))
                {
                    len = ft_strlen(st_->arg_str);
                    while (len++ < (size_t)st_->width)
                        ft_putchar_fd(' ', 1, p);
                }
                else
                {
                    len = (size_t)st_->precis;
                    while (len < (size_t)st_->width)
                    {
                        ft_putchar_fd(' ', 1, p);
                        len++;
                    }
                }
            }
        }
        if (st_->precis)
        {
            len2 = ft_strlen(st_->arg_str);
            i = -1;
            if (len2 > (size_t)st_->precis)
            {
                while (++i < (size_t)st_->precis)
                    ft_putchar_fd(st_->arg_str[i], 1, p);
            }
            else
                ft_putstr_fd(st_->arg_str, 1, p);

        }
        else
        {
            if (indic == 0)
                ft_putstr_fd(st_->arg_str, 1, p);
        }
    }
/*
** ************************************************
**                      FLAG -
** ************************************************
*/
    else
    {
        len = ft_strlen(st_->arg_str);
        i = 0;
        if (st_->precis || (!st_->precis && st_->is_precis == 1))
        {
            if ((st_->precis) && len > (size_t)st_->precis)
            {
                while (i < (size_t)st_->precis)
                {
                    ft_putchar_fd(st_->arg_str[i], 1, p);
                    i++;
                }
            }
            else
            {
                if (len <= (size_t)st_->precis)
                {
                    ft_putstr_fd(st_->arg_str, 1, p);
                    i += len;
                }
            }
        }
        else if (!st_->precis && !st_->is_precis)
        {
            ft_putstr_fd(st_->arg_str, 1, p);
            i += len;
        }
        if (st_->width)
        {
            while ((i < ((size_t)st_->width)))
            {
                ft_putchar_fd(' ', 1, p);
                i++;
            }
        }
    }
}