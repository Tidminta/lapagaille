/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 14:38:38 by tidminta          #+#    #+#             */
/*   Updated: 2020/03/18 17:26:04 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** *******************************************************************************************************
** 1. Fonction s'occupant du bon affichage du %u														**
** [flag zero] only matter if (width) | force number to be padded with 0 | ("%05d", 10) => [00010]		**
** [flag moins] only matter if (width) | force number to be left justified | ("%-3d", 10) => [10 ]		**
** ex ("%8.5d", 1234) ==> " | | |0|1234" [width = 8 | precis = 5 | len = 4]								**
** if (precision) flag zero ignoré																		**
** ft_display_struct(st_); 																				**
** sans width "%.10d" | precision = len (flag zero too) |  												**
** modifier touts les ft_itoa pour pouvoir free															**
** supprimer les lignes ne servant a rien au decoupage --> (st_->arg_uint > 0)							**
** *******************************************************************************************************
 */

void		ft_printf_unsigned(t_infos_ *st_, t_params_ *p)
{
	size_t	len;
	size_t	len2;
	size_t	len3;

	st_->flag_zero = (st_->flag_moins) ? 0 : st_->flag_zero;
	// ft_display_struct(st_);

	/*
	 ** **********************************
	 **		PAS DE FLAGS
	 **		SEMBLE FONCTIONNEL | CONTINUER LES TESTS
	 ** **********************************
	 */
	if (!st_->flag_moins && !st_->flag_zero)
	{
		len = ft_strlen(ft_itoa2(st_->arg_uint));
		/*
		 ** pas de flag zero pas de flag moins
		 **	width et precision
		 */
		if (st_->width && st_->precis)
		{
			if ((size_t)st_->precis > len)
			{
				len2 = (st_->arg_uint > 0) ? st_->width : (st_->width - 1);
				while (len2 > (size_t)st_->precis)
				{
					ft_putchar_fd(' ', 1, p);
					len2--;
				}
			}
			else
			{
				len3 = ft_strlen(ft_itoa2(st_->arg_uint));
				while (len3 < (size_t)st_->width)
				{
					ft_putchar_fd(' ', 1, p);
					len3++;
				}
			}
			len = (st_->arg_uint > 0) ? len : (len - 1);
			while (len < (size_t)st_->precis)
			{
				ft_putchar_fd('0', 1, p);
				len++;
			}
			ft_putnbr_base(st_->arg_uint, "0123456789", p);
		}
		/*
		 ** pas de flag zero pas de flag moins
		 **	width et pas de precision
		 */		
		else if (st_->width && !(st_->precis))
		{
			len2 = ft_strlen(ft_itoa2(st_->arg_uint));
			while (len2 < (size_t)st_->width)
			{	
				ft_putchar_fd(' ', 1, p);
				len2++;
			}
			ft_putnbr_base(st_->arg_uint, "0123456789", p);
		}
		/*
		 ** pas de flag zero pas de flag moins
		 **	pas de width et precision
		 */
		else if (!(st_->width) && st_->precis)
		{
			len = ft_strlen(ft_itoa2(st_->arg_uint));
			len = (st_->arg_uint > 0) ? len : (len - 1);
			while (len < (size_t)st_->precis)
			{
				ft_putchar_fd('0', 1, p);
				len++;
			}
			ft_putnbr_base(st_->arg_uint, "0123456789", p);
		}
		else
		{
			ft_putnbr_base(st_->arg_uint, "0123456789", p);
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
		len = ft_strlen(ft_itoa2(st_->arg_uint));
		len2 = (st_->arg_uint > 0) ? st_->width : (st_->width - 1);
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
				len3 = ft_strlen(ft_itoa2(st_->arg_uint));
				while (len3 < (size_t)st_->width)
				{
					ft_putchar_fd(' ', 1, p);
					len3++;
				}
			}
		}
		/*
		 **	gestion affichage precision | et gestion du cas sans precision
		 */
		if (((st_->width && st_->precis) || (!st_->width && st_->precis)))
		{
			len = ft_strlen(ft_itoa2(st_->arg_uint));
			len = (st_->arg_uint > 0) ? len : len -1;
			while (len < (size_t)st_->precis)
			{
				ft_putchar_fd('0', 1, p);
				len++;
			}
		}
		else if ((st_->width) && !st_->is_precis)
		{
			len = ft_strlen(ft_itoa2(st_->arg_uint));
			while ((len < (size_t)st_->width))
			{
				ft_putchar_fd('0', 1, p);
				len++;
			}
		}
		ft_putnbr_base(st_->arg_uint, "0123456789", p);
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
		len = ft_strlen(ft_itoa2(st_->arg_uint));
		len2 = (st_->arg_uint > 0) ? st_->width : (st_->width - 1);
		/*
		 **	gestion affichage precision | et gestion du cas sans precision
		 */
		if (((st_->width && st_->precis) || (!st_->width && st_->precis)))
		{
			len = ft_strlen(ft_itoa2(st_->arg_uint));
			len = (st_->arg_uint > 0) ? len : len -1;
			while (len < (size_t)st_->precis)
			{
				ft_putchar_fd('0', 1, p);
				len++;
			}
		}
		ft_putnbr_base(st_->arg_uint, "0123456789", p);
		/*
		 ** gestion affichage width
		 */
		if (st_->width && !st_->precis)
		{
			len = ft_strlen(ft_itoa2(st_->arg_uint));
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
				len3 = ft_strlen(ft_itoa2(st_->arg_uint));
				while (len3 < (size_t)st_->width)
				{
					ft_putchar_fd(' ', 1, p);
					len3++;
				}
			}
		}
	}
}

