/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:00:08 by tidminta          #+#    #+#             */
/*   Updated: 2020/04/01 14:29:58 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** 1. Fonction qui check si la char en param est un flag
*/

char		ft_check_flag(char car)
{
	if (car == '#' || car == '-' || car == '0')
		return (1);
	return (0);
}

/*
** 2. Fonction qui check si la char en param est un specificateur de conversion
*/

char		ft_check_conv_spe(char car)
{
	if (car == 'c' || car == 's' || car == 'p' || car == 'd' || car == 'i'
		|| car == 'o' || car == 'u' || car == 'u' || car == 'x' || car == 'X'
			|| car == '%')
		return (car);
	return (0);
}

/*
** 3. Fonction qui recupere le flag
** A modifier ! Ne fonction que qd 1 seul flag est present
*/

void		ft_get_flag(const char *s, unsigned int *index, t_infos_ *struct_ptr_)
{
	while (s[*index] && s[*index] != '%')
		*index += 1;
	if (s[*index] == '%')
	{
		*index += 1;
		while (s[*index] && ft_check_flag(s[*index]))
		{
			if (!struct_ptr_->flag_zero)
				struct_ptr_->flag_zero = (s[*index] == '0') ? 1 : 0;
			if (!struct_ptr_->flag_moins)
				struct_ptr_->flag_moins = (s[*index] == '-') ? 1 : 0;
			if (!struct_ptr_->flag_diez)
				struct_ptr_->flag_diez = (s[*index] == '#') ? 1 : 0;
			*index += 1;
		}
	}
}

/*
** 4. Fonction qui recup la width
** Trouver moyen de ne pas utiliser Malloc
** modifier le retour de la fonction : 1 ou -1 && donner la precision directement dans la struct
*/

int			ft_get_width(const char *s, unsigned int *index, va_list *lst_ptr)
{
	unsigned int	j;
	int				width;
	char			*alloc;
	size_t			len;

	width = 0;
	len = 0;
	j = *index;

	(void)lst_ptr;
	// printf("[width][%c]", s[*index]);
	// if(s[*index] == '*')
	// {
	// 	width = va_arg(*lst_ptr, int);
	// 	*index += 1;
	// 	// printf("[width][%i]", width);
	// 	return (width);
	// }
	while (s[*index] && ft_isdigit(s[*index])
		&& (s[*index != '.'] || !(ft_check_conv_spe(s[*index]))))
	{
		*index += 1;
		len++;
	}
	if (!(alloc = ft_substr(s, j, len)))
		return (-1);
	width = ft_atoi(alloc);
	free(alloc);
	if (width > 0)
		return (width);
	return (0);
}

static void	ft_get_precis2(const char *s, unsigned int *i, t_infos_ *struct_ptr_)
{
	if (ft_check_conv_spe(s[*i]))
	{
		struct_ptr_->conv_spe = s[*i];
		*i += 1;
	}
}

/*
** 5. Fonction qui recup la precision et fill conversion specifier
** Trouver moyen de ne pas utiliser Malloc
** modifier le retour de la fonction : 1 ou -1 && donner la precision directement dans la struct
*/

int			ft_get_precis(const char *s, unsigned int *i, t_infos_ *struct_ptr_, va_list *lst_ptr)
{
	unsigned int	j;
	int				precis;
	char			*alloc;
	size_t			len;

	precis = 0;
	j = *i + 1;
	len = 0;
	alloc = NULL;
	(void)lst_ptr;
	if ((*i > 0) && s[*i] == '.')
	{
		struct_ptr_->is_precis = 1;
		// if(s[++(*i)] == '*')
		// {
		// 	precis = va_arg(*lst_ptr, int);
		// 	*i += 1;
		// 	ft_get_precis2(s, i, struct_ptr_);
		// 	return (precis);
		// }
		while (s[++(*i)] && ft_isdigit(s[*i]) && !(ft_check_conv_spe(s[*i])))
		{
			len++;
		}
		if (len)
		{
			if (!(alloc = ft_substr(s, j, len)))
				return (-1);
			precis = ft_atoi(alloc);
			free(alloc);
		}
	}
	ft_get_precis2(s, i, struct_ptr_);
	return (precis);
}
