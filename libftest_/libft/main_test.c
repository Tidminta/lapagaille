/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 23:30:00 by tidminta          #+#    #+#             */
/*   Updated: 2019/12/18 17:45:08 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "libft.h"

void	ft_print_result(int n)
{
	char c;

	if (n >= 10)
		ft_print_result(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

unsigned int            ft_is_present(char const *s, unsigned int *index, char c)
{
    if (s[*index] == c)
        return (1);
    else
        return (0);
}

size_t          ft_fill(char const *s, unsigned int *index, char c)
{
    printf("FT_FILL");
    size_t len;
    len = 0;
    while (ft_is_present(s, *index, c) == 0)
    {
        len++;
        index++;
    }
    printf("len = %zu\n", len);
    return (len);
}

int		main(void)
{
	unsigned int i;
	char c;

	i = 0;
	if (ft_is_present("Paris est magique", &i, c) == 0)
	{
		ft_fill("Paris est magique", &i, c);
	}
	return (0);
}
