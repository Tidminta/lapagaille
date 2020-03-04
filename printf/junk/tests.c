/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:13:08 by tidminta          #+#    #+#             */
/*   Updated: 2020/03/04 15:33:40 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../lib/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// int             ft_isdigit(int c)
// {
//         return (c >= '0' && c <= '9');
// }

// char		ft_check_conv_spe(char car)
// {
// 	if (car == 'c' || car == 's' || car == 'p' || car == 'd' || car == 'i'
// 		|| car == 'o' || car == 'u' || car == 'u' || car == 'x' || car == 'X')
// 		return (car);
// 	return (0);
// }

// size_t		ft_strncopy(char **dst, const char *src, int start, size_t dstsize)
// {
// 	size_t	j;
// 	int k;

// 	j = 0;
// 	k = 0;
// 	if (!src || !dst)
// 		return (0);
// 	if (dstsize == 0)
// 		return (start);
// 	while (j < dstsize - 1)
// 	{
// 		(*dst)[j] = src[start];
// 		printf("[ft_strncopy][%zu] = [%c]\n", j, *dst[j]);
// 		j++;
// 		start += 1;
// 	}
// 	(*dst)[j] = '\0';
// 	return (1);
// }

typedef struct	s_infos_
{
	const char	*string;
	int			flag_zero;
	int			flag_moins;
	int			width;
	int			precis;
	char		conv_spe;
}				t_infos_;

void		ft_get_flag(char *s, int *index, t_infos_ *struct_ptr_)
{
	while (s[*index] && s[*index] != '%')
		*index += 1;
	if (s[*index] == '%')
	{
		*index += 1;
		struct_ptr_->flag_zero = (s[*index] == '0') ? 1 : 0;
		struct_ptr_->flag_moins = (s[*index] == '-') ? 1 : 0;
	}
}

t_infos_	*ft_init_struct(void)
{
	t_infos_ *ptr;

	ptr = (t_infos_ *)malloc(sizeof(t_infos_));
	ptr->string = 0;
	ptr->flag_zero = 0;
	ptr->flag_moins = 0;
	ptr->width = 0;
	ptr->precis = 0;
	return (ptr);
}

int		ft_sumnum(int nb, ...)
{
	va_list list_ptr;
	int		sum;
	int		i;

	sum = 0;
	i = 0;
	va_start(list_ptr, nb);
	while (i < nb)
	{
		printf("argument[%d] = %d\n", i, va_arg(list_ptr, int));
		i++;
	}
	va_end(list_ptr);
	return (sum);
}

int			ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

char	ft_convert_char(int char_)
{
	if (ft_isprint(char_))
		return ((char)char_);
	return (0);
}

int		main(void)
{
	t_infos_	*test_ptr;
	char		*str;
	int			char_;
	// void		*char_convert;
	int			nb;
	int			i;

	i = 0;
	nb = 1234;
	char_ = 66;
	str = "paris est %-c\n";
	test_ptr = ft_init_struct();
	printf("[init_struct] = %i\n", test_ptr->flag_zero);
	printf("[init_struct] = %i\n", test_ptr->flag_moins);
	ft_get_flag(str, &i, test_ptr);
	printf("[struct.zero] = %i\n", test_ptr->flag_zero);
	printf("[struct.moins] = %i\n", test_ptr->flag_moins);
	free(test_ptr);
	ft_sumnum(5, 0, 1, 2, 3, 4);
	// printf("[test c] [%-c]\n", char_);
	// printf("[char_convert] = [%c]", (char)char_convert);
	// system("leaks a.out");
	return (0);
}
