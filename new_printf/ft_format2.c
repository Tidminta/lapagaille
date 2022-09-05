/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 21:23:00 by tidminta          #+#    #+#             */
/*   Updated: 2020/04/14 21:17:56 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** 1. Fonction qui recuperer l'argument actuel
** %p necessite peut etre un type long long ?
*/

void	ft_get_arg(va_list *list_ptr, t_infos_ *struct_ptr)
{
	if (struct_ptr->conv_spe == 'c')
		struct_ptr->arg_char = va_arg(*list_ptr, int);
	else if (struct_ptr->conv_spe == 's')
	{
		struct_ptr->arg_str = va_arg(*list_ptr, char *);
		if (!struct_ptr->arg_str)
			struct_ptr->arg_str = "(null)";
	}
	else if (struct_ptr->conv_spe == 'p')
		struct_ptr->arg_addr = va_arg(*list_ptr, unsigned long);
	else if (struct_ptr->conv_spe == 'd' || struct_ptr->conv_spe == 'i')
		struct_ptr->arg_int = va_arg(*list_ptr, int);
	else if (struct_ptr->conv_spe == 'u')
		struct_ptr->arg_uint = va_arg(*list_ptr, unsigned int);
	else if (struct_ptr->conv_spe == 'x')
		struct_ptr->arg_hexa = va_arg(*list_ptr, unsigned long);
	else if (struct_ptr->conv_spe == 'X')
		struct_ptr->arg_hexa = va_arg(*list_ptr, unsigned long);
	else if (struct_ptr->conv_spe == '%')
		struct_ptr->arg_char = '%';
	else if (struct_ptr->conv_spe == 'b')
		struct_ptr->arg_bin = va_arg(*list_ptr, unsigned long);
}

/*
** 2. Fonction rempli la struct avec les differentes infos
**	ft_display_struct(stct_p);
*/

void	ft_fill(t_infos_ *stct_p, va_list *lst_p, const char *s, t_params_ *p)
{
	ft_get_flag(s, p, stct_p);
	stct_p->width = ft_get_width(s, p, lst_p);
	ft_get_p(s, p, stct_p, lst_p);
	ft_get_arg(lst_p, stct_p);
	if (stct_p->width < 0)
	{
		stct_p->width *= -1;
		stct_p->flag_moins = 1;
	}
	if (stct_p->precis < 0)
		stct_p->is_precis = 0;
	else
		stct_p->is_precis = stct_p->is_precis;
	if (stct_p->precis < 0)
		stct_p->precis = 0;
	else
		stct_p->precis = stct_p->precis;
}

char	ft_check_flag(char car)
{
	if (car == '#' || car == '-' || car == '0')
		return (1);
	return (0);
}
