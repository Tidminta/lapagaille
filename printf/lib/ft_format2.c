/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 21:23:00 by tidminta          #+#    #+#             */
/*   Updated: 2020/03/09 15:33:41 by tidminta         ###   ########.fr       */
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
		struct_ptr->arg_str = va_arg(*list_ptr, char *);
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
}

/*
** 2. Fonction rempli la struct avec les differentes infos
*/

void	ft_fill_struct(t_infos_ *stct_p, va_list *lst_p, const char *s, int *i)
{
	ft_get_flag(s, i, stct_p);
	stct_p->width = ft_get_width(s, i);
	stct_p->precis = ft_get_precis(s, i, stct_p);
	ft_get_arg(lst_p, stct_p);
}
