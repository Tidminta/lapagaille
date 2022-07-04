/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:49:56 by tidminta          #+#    #+#             */
/*   Updated: 2020/01/17 20:04:25 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <malloc/malloc.h>

// int main(void)
// {
//         signal(SIGSEGV, sigsegv);
//         title("ft_strchr\t: ")
//         char s[] = "tripouille";
//         /* 1 */ check(ft_strchr(s, 't') == s); showLeaks();
//         /* 2 */ check(ft_strchr(s, 'l') == s + 7); showLeaks();
//         /* 3 */ check(ft_strchr(s, 'z') == 0); showLeaks();
//         /* 4 */ check(ft_strchr(s, 0) == s + strlen(s)); showLeaks();
//         /* 5 */ check(ft_strchr(s, 't' + 256) == s); showLeaks();
//         write(1, "\n", 1);
//         return (0);
// }

int main(void)
{
	char **s;
	int	i;
	void *p2;

	s =  ft_split("tripouille ", ' ');
	p2 = malloc(sizeof(char *) * 2);
	i = 0;
	while (s[i])
	{
		printf("[%s]\n", s[i]);
		i++;
	}
	printf("split = %zu\n", malloc_size(s)); 
	printf("malloc = %zu\n", malloc_size(p2)); 
	free(s);
	return (0);
}