/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_structs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:41:03 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/04 18:55:16 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_infos_	*ft_init_struct(void)
{
	t_infos_ *ptr;

	ptr = (t_infos_ *)malloc(sizeof(t_infos_));
	ptr->conv_spe = 0;
	ptr->flag_zero = 0;
	ptr->flag_moins = 0;
	ptr->flag_diez = 0;
	ptr->width = 0;
	ptr->precis = 0;
	ptr->is_precis = 0;
	ptr->conv_len = 0;
	ptr->arg_char = 0;
	ptr->arg_int = 0;
	ptr->arg_uint = 0;
	ptr->arg_addr = 0;
	ptr->arg_hexa = 0;
	ptr->arg_str = 0;
	return (ptr);
}

/*
** 4. Fonction qui init la struct_params
*/

t_params_	*ft_init_params(void)
{
	t_params_ *ptr;

	ptr = (t_params_ *)malloc(sizeof(t_params_));
	ptr->conv_len = 0;
	ptr->index = 0;
	return (ptr);
}
