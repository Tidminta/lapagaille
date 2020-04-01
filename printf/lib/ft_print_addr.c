/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 20:22:39 by tidminta          #+#    #+#             */
/*   Updated: 2020/03/23 16:09:13 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
 ** *****************************************************************************
 **                FONCTION D'AFFICHAGE %P 
 **  No precision | [%19.c] ==> [%19c]
 **  No 0 flag
 **  No # flag
 **  width | flag moins
 **  SEMBLE FONCTIONNEL
 ** ******************************************************************************
 */


void        ft_printf_addr(t_infos_ *st_, t_params_ *p)
{

	size_t  len;
	size_t  width_len;
    size_t  precis_len;
	size_t  tmp;

	// ft_display_struct(st_);
	len = 1;
	tmp = st_->arg_addr;
	while (tmp && ((tmp/16) > 0))
	{
		tmp = tmp/16;
		len++;
	}
	/*
	 ** ********************************************************************
	 **		                    PAS DE FLAGS
	 **		                    SEMBLE FONCTIONNER
	 ** ********************************************************************
	 */
	if (!st_->flag_zero && !st_->flag_diez && !st_->flag_moins)
	{
		if (st_->width && st_->precis)
		{
			width_len = st_->width;
            precis_len = ((size_t)st_->precis < len) ? len + 2 : st_->precis + 2 ; 
			while ((width_len) > precis_len)
			{
				ft_putchar_fd(' ', 1, p);
				width_len--;
			}
			ft_putstr_fd("0x", 1, p);
			while ((len) < (size_t)st_->precis)
			{
				ft_putchar_fd('0', 1, p);
				len++;
			}
            if (st_->precis != 0)
			    ft_putnbr_base(st_->arg_addr, "0123456789abcdef", p);
		}
		else if (st_->width && !st_->precis)
		{
			len = (st_->arg_addr == 0 && st_->is_precis) ? 2 : len + 2;
			while (len++ < (size_t)st_->width)
				ft_putchar_fd(' ', 1 , p);
			ft_putstr_fd("0x", 1, p);
            if (st_->arg_addr == 0 && !st_->is_precis)
			    ft_putnbr_base(st_->arg_addr, "0123456789abcdef", p);
            else if (st_->arg_addr != 0)
			    ft_putnbr_base(st_->arg_addr, "0123456789abcdef", p);
		}
		else if (!st_->width && st_->precis)
		{
			ft_putstr_fd("0x", 1, p);
			while ((len) < (size_t)st_->precis)
			{
				ft_putchar_fd('0', 1, p);
				len++;
			}
            if (st_->precis != 0)
			    ft_putnbr_base(st_->arg_addr, "0123456789abcdef", p);
		}
		else
		{
			ft_putstr_fd("0x", 1, p);
            if ((st_->arg_addr == 0 && st_->is_precis == 1))
                ;
			else
                ft_putnbr_base(st_->arg_addr, "0123456789abcdef", p);
		}
	}
	/*
	 ** ********************************************************************
	 **		                    FLAG MOINS
	 ** ********************************************************************
	 */
	else if (!(st_->flag_zero && st_->flag_diez) && (st_->flag_moins))
	{
		if (st_->width && st_->precis)
		{
			width_len = st_->width;
            precis_len = ((size_t)st_->precis < len) ? len + 2 : st_->precis + 2 ; 
			ft_putstr_fd("0x", 1, p);
			while ((len) < (size_t)st_->precis)
			{
				ft_putchar_fd('0', 1, p);
				len++;
			}
            if (st_->precis != 0)
			    ft_putnbr_base(st_->arg_addr, "0123456789abcdef", p);
			while ((width_len) > precis_len)
			{
				ft_putchar_fd(' ', 1, p);
				width_len--;
			}
		}
		else if (st_->width && !st_->precis)
		{
			len = (st_->arg_addr == 0 && st_->is_precis) ? 2 : len + 2;
			ft_putstr_fd("0x", 1, p);
            if (st_->arg_addr == 0 && !st_->is_precis)
			    ft_putnbr_base(st_->arg_addr, "0123456789abcdef", p);
            else if (st_->arg_addr != 0)
			    ft_putnbr_base(st_->arg_addr, "0123456789abcdef", p);
			while (len++ < (size_t)st_->width)
				ft_putchar_fd(' ', 1 , p);
		}
		else if (!st_->width && st_->precis)
		{
			ft_putstr_fd("0x", 1, p);
			while ((len) < (size_t)st_->precis)
			{
				ft_putchar_fd('0', 1, p);
				len++;
			}
            if (st_->precis != 0)
			    ft_putnbr_base(st_->arg_addr, "0123456789abcdef", p);
		}
		else
		{
			ft_putstr_fd("0x", 1, p);
            if ((st_->arg_addr == 0 && st_->is_precis == 1))
                ;
			else
                ft_putnbr_base(st_->arg_addr, "0123456789abcdef", p);
		}
	}
}
