/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 16:27:51 by tidminta          #+#    #+#             */
/*   Updated: 2020/04/01 16:41:40 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void        ft_printf_bin(t_infos_ *st_, t_params_ *p)
{
size_t	first_len;
	size_t	tmp;
	size_t	len;
	size_t	len2;
	size_t	len3;
	
	st_->flag_zero = (st_->flag_moins) ? 0 : st_->flag_zero;
	tmp = st_->arg_bin;
	first_len = 1;
	while(tmp && (tmp/2) > 0)
	{
		tmp /= 2;
		first_len++;
	}
	// ft_display_struct(st_);

	/*
	 ** **********************************
	 **		PAS DE FLAGS
	 **		SEMBLE FONCTIONNEL | CONTINUER LES TESTS
	 ** **********************************
	 */
	if (!st_->flag_moins && !st_->flag_zero)
	{
		len = first_len;
		/*
		 ** pas de flag zero pas de flag moins
		 **	width et precision
		 */
		if (st_->width && st_->precis)
		{
			if ((size_t)st_->precis > len)
			{
				len2 = (st_->arg_bin >= 0) ? st_->width : (st_->width - 1);
				while (len2 > (size_t)st_->precis)
				{
					ft_putchar_fd(' ', 1, p);
					len2--;
				}
			}
			else
			{
				len3 = first_len;
				while (len3 < (size_t)st_->width)
				{
					ft_putchar_fd(' ', 1, p);
					len3++;
				}
			}
			len = (st_->arg_bin >= 0) ? len : (len - 1);
			while (len < (size_t)st_->precis)
			{
				ft_putchar_fd('0', 1, p);
				len++;
			}
			ft_putnbr_base(st_->arg_bin, "01", p);
		}
		/*
		 ** pas de flag zero pas de flag moins
		 **	width et pas de precision
		 */		
		else if (st_->width && !(st_->precis))
		{
			len2 = (st_->arg_bin >= 0) ? first_len : first_len - 1;
			while (len2 < (size_t)st_->width)
			{	
				ft_putchar_fd(' ', 1, p);
				len2++;
			}
			if (!st_->arg_bin && st_->is_precis)
				ft_putchar_fd(' ', 1, p);
			else
				ft_putnbr_base(st_->arg_bin, "01", p);
		}
		/*
		 ** pas de flag zero pas de flag moins
		 **	pas de width et precision
		 */
		else if (!(st_->width) && st_->precis)
		{
			len = first_len;
			len = (st_->arg_bin >= 0) ? len : (len - 1);
			while (len < (size_t)st_->precis)
			{
				ft_putchar_fd('0', 1, p);
				len++;
			}
			ft_putnbr_base(st_->arg_bin, "01", p);
		}
		else
		{
			if (!st_->arg_bin && (st_->is_precis && !st_->precis))
				;
			else
				ft_putnbr_base(st_->arg_bin, "01", p);
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
		len = first_len;
		len2 = (st_->arg_bin >= 0) ? st_->width : (st_->width - 1);
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
				len3 = first_len;
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
			len = first_len;
			len = (st_->arg_bin >= 0) ? len : len -1;
			while (len < (size_t)st_->precis)
			{
				ft_putchar_fd('0', 1, p);
				len++;
			}
		}
		else if ((st_->width) && !st_->is_precis)
		{
			len = first_len;
			while ((len < (size_t)st_->width))
			{
				ft_putchar_fd('0', 1, p);
				len++;
			}
		}
		ft_putnbr_base(st_->arg_bin, "01", p);
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
		len = first_len;
		len2 = (st_->arg_bin >= 0) ? st_->width : (st_->width - 1);
		/*
		 **	gestion affichage precision | et gestion du cas sans precision
		 */
		if (((st_->width && st_->precis) || (!st_->width && st_->precis)))
		{
			len = first_len;
			len = (st_->arg_bin >= 0) ? len : len -1;
			while (len < (size_t)st_->precis)
			{
				ft_putchar_fd('0', 1, p);
				len++;
			}
		}
		if (!st_->arg_bin && (st_->is_precis && !st_->precis))
			;
		else
			ft_putnbr_base(st_->arg_bin, "01", p);
		/*
		 ** gestion affichage width
		 */
		if (st_->width && !st_->precis)
		{
			if (!st_->arg_bin && (st_->is_precis && !st_->precis))
				len -= 1;	
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
				len3 = first_len;
				while (len3 < (size_t)st_->width)
				{
					ft_putchar_fd(' ', 1, p);
					len3++;
				}
			}
		}
	}
}