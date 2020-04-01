/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_structs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:41:03 by tidminta          #+#    #+#             */
/*   Updated: 2020/03/25 16:52:41 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** 1. Fonction qui affiche la structure de type t_infos
*/

void		ft_display_struct(t_infos_ *struct_ptr)
{
	printf("\n*************************\n");
	printf("[conv_spe] [%c]\n", struct_ptr->conv_spe);
	printf("[flag_zero] [%d]\n", struct_ptr->flag_zero);
	printf("[flag_moins] [%d]\n", struct_ptr->flag_moins);
	printf("[flag_diez] [%d]\n", struct_ptr->flag_diez);
	printf("[width] [%d]\n", struct_ptr->width);
	printf("[precis] [%d]\n", struct_ptr->precis);
	printf("[is precis] [%d]\n", struct_ptr->is_precis);
	printf("[conv_len] [%d]\n", struct_ptr->conv_len);
	printf("[arg_char] [%d]\n", struct_ptr->arg_char);
	printf("[arg_int] [%d]\n", struct_ptr->arg_int);
	printf("[arg_uint] [%u]\n", struct_ptr->arg_uint);
	printf("[arg_addr] [%lu]\n", struct_ptr->arg_addr);
	printf("[arg_hexa] [%u]\n", struct_ptr->arg_hexa);
	printf("[arg_str] [%s]\n", struct_ptr->arg_str);
	printf("*************************\n");
}

/*
** 2. Fonction qui affiche la structure de type t_params_
*/

void		ft_display_params(t_params_ *struct_ptr)
{
	printf("\n*************************\n");
	printf("[t_params index][%i]\n", struct_ptr->index);
	printf("[t_params][%i]\n", struct_ptr->conv_len);
	printf("*************************\n");
}

/*
** 3. Fonction qui init la struct_info
*/

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
