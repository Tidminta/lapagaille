/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 19:55:20 by tidminta          #+#    #+#             */
/*   Updated: 2020/03/18 16:46:21 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
 ** 1. Fonction s'occupant du bon affichage du %x
 ** [flag zero] only matter if (width) | force number to be padded with 0 | ("%05d", 10) => [00010]
 ** [flag moins] only matter if (width) | force number to be left justified | ("%-3d", 10) => [10 ]
 ** ex ("%8.5d", 1234) ==> " | | |0|1234" [width = 8 | precis = 5 | len = 4]
 ** if (precision) flag zero ignoré
 ** ft_display_struct(st_);
 ** modifier touts les ft_itoa pour pouvoir free 
 ** supprimer les lignes ne servant a rien au decoupage --> (st_->arg_uint > 0)
 ** len3 = (st_->flag_diez) ? (st_->is_precis + 2) : st_->is_precis;
 */

void		ft_printf_hexa(t_infos_ *st_, t_params_ *p)
{
	size_t	len;
	size_t	len2;
	size_t	len3;
	size_t	tmp;

	st_->flag_zero = (st_->flag_moins) ? 0 : st_->flag_zero;
	// ft_display_struct(st_);

	/*
	 ** **********************************
	 **		PAS DE FLAGS
	 **		SEMBLE FONCTIONNER
	 ** **********************************
	 */
	if (!st_->flag_moins && !st_->flag_zero)
	{
		tmp = st_->arg_hexa;
		len = 1;
		while (tmp && ((tmp/10) > 16))
		{
			tmp = tmp/16;
			len++;
		}
		/*
		 ** *************************************************************
		 ** 		pas de flag zero pas de flag moins
		 **			width et precision
		 ** *************************************************************
		 */
		if (st_->width && st_->precis)
		{
			if ((size_t)st_->precis > len)
			{
				len2 = (st_->flag_diez) ? ((st_->width > 1) ? st_->width - 2 : 0) : st_->width;
				while (len2 > (size_t)st_->precis)
				{
					ft_putchar_fd(' ', 1, p);
					len2++;
				}
			}
			else
			{
				len3 = (st_->flag_diez) ? (len + 2) : len;
				while (len3 < (size_t)st_->width)
				{
					ft_putchar_fd(' ', 1, p);
					len3++;
				}
			}
			if (st_->flag_diez)
				ft_putstr_fd("0x", 1, p);
			while (len < (size_t)st_->precis)
			{
				ft_putchar_fd('0', 1, p);
				len++;
			}
			if (st_->conv_spe == 'x')
				ft_putnbr_base(st_->arg_hexa, "0123456789abcdef", p);
			else
				ft_putnbr_base(st_->arg_hexa, "0123456789ABCDEF", p);

		}
		/*
		 ** *************************************************************
		 ** 		pas de flag zero pas de flag moins
		 **			width et pas de precision
		 ** *************************************************************
		 */		
		else if (st_->width && !(st_->precis))
		{
			len2 = (st_->flag_diez) ? (len + 2) : len;
			while (len2 < (size_t)st_->width)
			{	
				ft_putchar_fd(' ', 1, p);
				len2++;
			}
			if (st_->flag_diez)
				ft_putstr_fd("0x", 1, p);
			if (st_->conv_spe == 'x')
				ft_putnbr_base(st_->arg_hexa, "0123456789abcdef", p);
			else
				ft_putnbr_base(st_->arg_hexa, "0123456789ABCDEF", p);
		}
		/*
		 ** pas de flag zero pas de flag moins
		 **	pas de width et precision
		 */
		else if (!(st_->width) && st_->precis)
		{
			if (st_->flag_diez)
				ft_putstr_fd("0x", 1, p);
			while (len < (size_t)st_->precis)
			{
				ft_putchar_fd('0', 1, p);
				len++;
			}
			ft_putnbr_base(st_->arg_hexa, "0123456789abcdef", p);
		}
		else
		{
			if (st_->flag_diez)
				ft_putstr_fd("0x", 1, p);
			if (st_->conv_spe == 'x')
				ft_putnbr_base(st_->arg_hexa, "0123456789abcdef", p);
			else
				ft_putnbr_base(st_->arg_hexa, "0123456789ABCDEF", p);
		}
	}
	/*
	 ** **********************************
	 **		FLAG ZERO
	 **	exemple : [width]|[nbr]|[precision]
	 **		SEMBLE FONCTIONNEL
	 ** **********************************
	 */
	else if ((st_->flag_zero && !st_->flag_moins))
	{
		tmp = st_->arg_hexa;
		len = 1;
		while (tmp && ((tmp/10) > 16))
		{
			tmp = tmp/16;
			len++;
		}
		/*
		 ** *************************************************************
		 ** 				gestion affichage width
		 ** *************************************************************
		 */
		if (st_->width && st_->precis) 
		{
			if ((size_t)st_->precis >= len)
			{
				len2 = (st_->flag_diez) ? ((st_->width > 1) ? st_->width - 2 : 0) : st_->width;
				while (len2 > (size_t)st_->precis)
				{
					ft_putchar_fd(' ', 1, p);
					len2--;
				}
			}
			else if ((size_t)st_->precis < len)
			{
				len3 = (st_->flag_diez) ? (len + 2) : len;
				while (len3 < (size_t)st_->width)
				{
					ft_putchar_fd(' ', 1, p);
					len3++;
				}
			}
		}
		else if (((st_->width && !st_->precis) && st_->is_precis))
		{
			len3 = (st_->flag_diez) ? (len + 2) : len;
			while (len3 < (size_t)st_->width)
			{
				ft_putchar_fd(' ', 1, p);
				len3++;
			}
		}
		/*
		 ** *************************************************************
		 **	gestion affichage precision | et gestion du cas sans precision
		 ** *************************************************************
		 */
		if (st_->flag_diez)
				ft_putstr_fd("0x", 1, p);
		if (((st_->width && st_->precis) || (!st_->width && st_->precis)))
		{
			while (len < (size_t)st_->precis)
			{
				ft_putchar_fd('0', 1, p);
				len++;
			}
		}
		else if ((st_->width) && !st_->is_precis)
		{
			// printf("cas 3\n");
			len = (st_->flag_diez) ? (len + 2) : len ;
			while ((len < (size_t)st_->width))
			{
				ft_putchar_fd('0', 1, p);
				len++;
			}
		}
		if (st_->conv_spe == 'x')
			ft_putnbr_base(st_->arg_hexa, "0123456789abcdef", p);
		else
			ft_putnbr_base(st_->arg_hexa, "0123456789ABCDEF", p);
	}
	/*
	 ** **********************************
	 **		FLAG MOINS
	 **		FAIL :
	 **	exemple : [precision]|[nbr]|[width]
	 ** **********************************
	 */
	else if (st_->flag_moins && !st_->flag_zero)
	{
		tmp = st_->arg_hexa;
		len = 1;
		while (tmp && ((tmp/10) > 16))
		{
			tmp = tmp/16;
			len++;
		}
		if (st_->flag_diez && (st_->arg_hexa != 0))
			ft_putstr_fd("0x", 1, p);	
		/*
		 ** *************************************************************
		 **	gestion affichage precision | et gestion du cas sans width
		 ** *************************************************************c
		 */
		if (((st_->width && st_->precis) || (!st_->width && st_->precis)))
		{
			// len = ft_strlen(ft_itoa2(st_->arg_uint));
			// len = (st_->arg_hexa > 0) ? len : len -1;
			while (len < (size_t)st_->precis)
			{
				ft_putchar_fd('0', 1, p);
				len++;
			}
		}	
		if (st_->conv_spe == 'x')
			ft_putnbr_base(st_->arg_hexa, "0123456789abcdef", p);
		else
			ft_putnbr_base(st_->arg_hexa, "0123456789ABCDEF", p);
		/*
		 ** *************************************************************
		 ** 				gestion affichage width
		 ** *************************************************************
		 */
		if (st_->width && !st_->precis)
		{
			len2 = (st_->flag_diez) ? (len + 2) : len;
			while ((len2 < (size_t)st_->width))
			{
				ft_putchar_fd(' ', 1, p);
				len2++;
			}
		}
		else if (st_->width && st_->precis) 
		{
			if ((st_->width) && (st_->is_precis) && (size_t)st_->precis >= len)
			{
				len2 = (st_->flag_diez) ? ((st_->width > 1) ? st_->width - 2 : 0) : st_->width;
				while (len2 > (size_t)st_->precis)
				{
					ft_putchar_fd(' ', 1, p);
					len2--;
				}
			}
			else if ((st_->width) && (st_->is_precis) && (size_t)st_->precis < len)
			{
				len3 = (st_->flag_diez) ? (len + 2) : len;
				while (len3 < (size_t)st_->width)
				{
					ft_putchar_fd(' ', 1, p);
					len3++;
				}
			}
		}
	}
}
