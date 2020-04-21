/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:05:24 by tidminta          #+#    #+#             */
/*   Updated: 2020/04/20 20:34:17 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** 1. Fonction qui check si le char est un affichage implicite. Ex '\n'
*/

int		ft_specific_print(char c)
{
	if (c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f' || c == '\b')
	{
		return (1);
	}
	return (0);
}

/*
** 2. Fonction qui affiche la string jusqu'au prochain '%'
*/

void	ft_print_loop(const char *str, t_params_ *p)
{
	char	*tmp;
	size_t	ret;
	size_t	len;

	ret = p->index;
	len = 0;
	tmp = NULL;
	if (str[p->index] && str[p->index] != '%')
	{
		while (str[p->index] && str[p->index] != '%')
		{
			p->index += 1;
			len++;
		}
		tmp = ft_substr(str, ret, len);
		ft_putstr_fd2(tmp, 1, p);
		free(tmp);
	}
}

/*
** 3. Fonction qui affiche l'argument
** utiliser les pointeurs sur fonctions
*/

void	ft_print_arg(t_infos_ *stct_, va_list *lst, const char *s, t_params_ *p)
{
	if (s[p->index] == '%')
	{
		ft_fill(stct_, lst, s, p);
		if (stct_->conv_spe == 'd' || stct_->conv_spe == 'i')
			ft_printf_digits(stct_, p);
		else if (stct_->conv_spe == 'c')
			ft_printf_char(stct_, p);
		else if (stct_->conv_spe == '%')
			ft_printf_pourcent(stct_, p);
		else if (stct_->conv_spe == 's')
			ft_printf_string(stct_, p);
		else if (stct_->conv_spe == 'u')
			ft_printf_unsigned(stct_, p);
		else if (stct_->conv_spe == 'x' || stct_->conv_spe == 'X')
			ft_printf_hexa(stct_, p);
		else if (stct_->conv_spe == 'p')
			ft_printf_addr(stct_, p);
		else if (stct_->conv_spe == 'b')
			ft_printf_bin(stct_, p);
	}
}
