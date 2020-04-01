/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:30:28 by tidminta          #+#    #+#             */
/*   Updated: 2020/03/26 19:09:20 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
 ** 1. Fonction s'occupant du bon affichage des %i & %d
 ** [flag zero] only matter if (width) | force number to be padded with 0 | ("%05d", 10) => [00010]
 ** [flag moins] only matter if (width) | force number to be left justified | ("%-3d", 10) => [10 ]
 ** ex ("%8.5d", 1234) ==> " | | |0|1234" [width = 8 | precis = 5 | len = 4]
 ** if (precision) flag zero ignoré
 ** ft_display_struct(st_); 
 ** sans width "%.10d" | precision = len (flag zero too) |
 ** modifier touts les ft_itoa pour pouvoir free
 **	test
 */

void		ft_printf_digits(t_infos_ *st_, t_params_ *p)
{
	size_t	first_len;
	size_t	len;
	size_t	len2;
	size_t	len3;
	size_t	tmp;

	st_->flag_zero = (st_->flag_moins) ? 0 : st_->flag_zero;
 	// ft_display_struct(st_);
	tmp = st_->arg_int;
	first_len = (st_->arg_int >= 0) ? 1 : 2;
	tmp = (st_->arg_int < 0) ? -st_->arg_int : st_->arg_int;
	while(tmp && (tmp/10) > 0)
	{
		tmp /= 10;
		first_len++;
	}

/*
** **********************************
**		PAS DE FLAGS
**		SEMBLE FONCTIONNEL | CONTINUER LES TESTS
** **********************************
*/
	if (!st_->flag_moins && !st_->flag_zero)
	{
		len = first_len;//
		/*
		 ** pas de flag zero pas de flag moins
		 **	width et precision
		 */
		if (st_->width && st_->precis)
		{
			if ((size_t)st_->precis > len)
			{
				len2 = (st_->arg_int >= 0) ? st_->width : (st_->width - 1);
				while (len2 > (size_t)st_->precis)
				{
					ft_putchar_fd(' ', 1, p);
					len2--;
				}
			}
			else
			{
				len3 = first_len;//
				while (len3 < (size_t)st_->width)
				{
					ft_putchar_fd(' ', 1, p);
					len3++;
				}
			}
			if (st_->arg_int < 0)
				ft_putchar_fd('-', 1, p);
			len = (st_->arg_int >= 0) ? len : (len - 1);
			while (len < (size_t)st_->precis)
			{
				ft_putchar_fd('0', 1, p);
				len++;
			}
			ft_putnbr_fd(st_->arg_int, 1, p);
		}
		/*
		 ** pas de flag zero pas de flag moins
		 **	width et pas de precision
		 */		
		else if (st_->width && !(st_->precis))
		{
			len2 = (!st_->arg_int && !st_->precis && st_->is_precis) ? first_len - 1 : first_len;
			while (len2 < (size_t)st_->width)
			{	
				ft_putchar_fd(' ', 1, p);
				len2++;
			}
			if (!st_->arg_int && (!st_->precis && st_->is_precis))
				;
			else
			{			
				if (st_->arg_int < 0)
					ft_putchar_fd('-', 1, p);
				ft_putnbr_fd(st_->arg_int, 1, p);
			}
		}
		/*
		 ** pas de flag zero pas de flag moins
		 **	pas de width et precision
		 */
		else if (!(st_->width) && st_->precis)
		{
			len = first_len;//
			len = (st_->arg_int >= 0) ? len : (len - 1);			
			if (st_->arg_int < 0)
				ft_putchar_fd('-', 1, p);
			while (len < (size_t)st_->precis)
			{
				ft_putchar_fd('0', 1, p);
				len++;
			}
			ft_putnbr_fd(st_->arg_int, 1, p);
		}
		else
		{
			if (!st_->arg_int && (!st_->precis && st_->is_precis))
				;
			else
			{
				if (st_->arg_int < 0)
					ft_putchar_fd('-', 1, p);
				ft_putnbr_fd(st_->arg_int, 1, p);
			}
		}
	}
/*
** **********************************
**		FLAG ZERO
**	exemple : [width]|[nbr]|[precision]
**	SEMBLE FONCTIONNEL | FAIL : [%020.d]
** **********************************
*/
	else if ((st_->flag_zero && !st_->flag_moins))
	{
		len = first_len;//
		len2 = (st_->arg_int >= 0) ? st_->width : (st_->width - 1);
		/*
		 ** gestion affichage width
		 */
		if (st_->width && st_->precis) 
		{
			if ((st_->width) && (st_->is_precis) && (size_t)st_->precis >= len)
			{
				while (len2 > (size_t)st_->precis)
				{
					ft_putchar_fd(' ', 1, p);
					len2--;
				}
			}
			else if ((st_->width) && (st_->is_precis) && (size_t)st_->precis < len)
			{
				len3 = first_len;//
				while (len3 < (size_t)st_->width)
				{
					ft_putchar_fd(' ', 1, p);
					len3++;
				}
			}
		}
		if (st_->arg_int < 0)
			ft_putchar_fd('-', 1, p);
		/*
		 **	gestion affichage precision | et gestion du cas sans precision
		 */
		if (((st_->width && st_->precis) || (!st_->width && st_->precis)))
		{
			len = first_len;//
			len = (st_->arg_int >= 0) ? len : len -1;
			while (len < (size_t)st_->precis)
			{
				ft_putchar_fd('0', 1, p);
				len++;
			}
		}
		else if ((st_->width) && !st_->is_precis)
		{
			len = first_len;//
			while ((len < (size_t)st_->width))
			{
				ft_putchar_fd('0', 1, p);
				len++;
			}
		}
		ft_putnbr_fd(st_->arg_int, 1, p);
	}
/*
** **********************************
**		FLAG MOINS
**		PAS COMPLET | FAIL :
**	exemple : [precision]|[nbr]|[width]
** **********************************
*/
	else if (st_->flag_moins && !st_->flag_zero)
	{
		len = first_len;//
		len2 = (st_->arg_int >= 0) ? st_->width : (st_->width - 1);
		if (st_->arg_int < 0)
			ft_putchar_fd('-', 1, p);
		/*
		 **	gestion affichage precision | et gestion du cas sans precision
		 */
		if (((st_->width && st_->precis) || (!st_->width && st_->precis)))
		{
			len = first_len;//
			len = (st_->arg_int >= 0) ? len : len -1;
			while (len < (size_t)st_->precis)
			{
				ft_putchar_fd('0', 1, p);
				len++;
			}
		}
		if (!st_->arg_int && (!st_->precis && st_->is_precis))
			;
		else
			ft_putnbr_fd(st_->arg_int, 1, p);
		/*
		 ** gestion affichage width
		 */
		if (st_->width && !st_->precis)
		{
			len = (!st_->arg_int && !st_->precis && st_->is_precis) ? first_len - 1 : first_len;
			while ((len < (size_t)st_->width))
			{
				ft_putchar_fd(' ', 1, p);
				len++;
			}
		}
		else if (st_->width && st_->precis) 
		{
			if ((st_->width) && (st_->is_precis) && (size_t)st_->precis >= len)
			{
				while (len2 > (size_t)st_->precis)
				{
					ft_putchar_fd(' ', 1, p);
					len2--;
				}
			}
			else if ((st_->width) && (st_->is_precis) && (size_t)st_->precis < len)
			{
				len3 = first_len;//
				while (len3 < (size_t)st_->width)
				{
					ft_putchar_fd(' ', 1, p);
					len3++;
				}
			}
		}
	}
}
