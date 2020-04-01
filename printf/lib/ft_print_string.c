/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 18:05:27 by tidminta          #+#    #+#             */
/*   Updated: 2020/03/30 23:47:52 by tidminta         ###   ########.fr       */
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
 **  FAILS : SANS PRECISION ET SEGFAULT QUAND NULL
 ** VOIR RESULT.TXT
 ** ******************************************************************************
 */

void        ft_printf_string(t_infos_ *st_, t_params_ *p)
{
	size_t  len;
	size_t  len2;
	size_t  indic;
	size_t  i;

	// ft_display_struct(st_);
	/*
	 ** ************************************************
	 **                  NO FLAG -
     **             len = 6 -> strlen((null))
	 ** ************************************************
	 */
	indic = 0;
	if (!st_->flag_moins)
	{
		len = (st_->arg_str) ? ft_strlen(st_->arg_str) : 6;
        // printf("[len][%lu]\n", len);
		/*
		 ** ************************************************
		 **       gestion de la width
		 ** ************************************************
		 */
		if (st_->width)
		{
            // printf("(53\n");
			i = -1;
			if (!st_->precis && st_->is_precis == 1)
			{
                // printf("57\n");
				while (++i < (size_t)st_->width)
					ft_putchar_fd(' ', 1, p);
				indic = 1;
			}
			else if (!st_->precis)
			{
                // printf("64\n");
		        len = (st_->arg_str) ? ft_strlen(st_->arg_str) : 6;
				while (len++ < (size_t)st_->width)
					ft_putchar_fd(' ', 1, p);
			}
			else
			{
                // printf("71\n");
				if ((len < (size_t)st_->precis))
				{
                    // printf("74");
					len = (st_->arg_str) ? ft_strlen(st_->arg_str) : 6;
					while (len++ < (size_t)st_->width)
						ft_putchar_fd(' ', 1, p);
				}
				else
				{
                    // printf("81");
					len = (size_t)st_->precis;
					while (len < (size_t)st_->width)
					{
						ft_putchar_fd(' ', 1, p);
						len++;
					}
				}
			}
		}
		/*
		 ** ************************************************
		 **          gestion de la precision
		 ** ************************************************
		 */     

		if (st_->precis)
		{
			len2 = (st_->arg_str) ? ft_strlen(st_->arg_str) : 6;
			i = -1;
            // printf("102\n");
			if (len2 > (size_t)st_->precis)
			{
                if (!st_->arg_str)
                {
                    // printf("107/n");
                    ft_putstr_fd(st_->arg_str, 1, p);
                }
                else
                {
                    // printf("111");
                    while (++i < (size_t)st_->precis)
                    ft_putchar_fd(st_->arg_str[i], 1, p);
                }			
            }
			else
            {
                // printf("109\n");
				ft_putstr_fd(st_->arg_str, 1, p);
            }
		}
		else 
		{
            // printf("116\n");
			if (indic == 0 && !st_->is_precis)
			{
                // printf("119\n");
				ft_putstr_fd(st_->arg_str, 1, p);
			}
                // printf("122\n");
		}
	}
	/*
	 ** ************************************************
	 **                      FLAG -
	 ** ************************************************
	 */
	else
	{
		len = (st_->arg_str) ? ft_strlen(st_->arg_str) : 6;
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
