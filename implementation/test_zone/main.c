/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:44:50 by tidminta          #+#    #+#             */
/*   Updated: 2021/08/16 21:50:34 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libshell.h"

int main(void)
{
	char *str;
	char *ret;

	str = strdup("HOME=/Users/tidminta");
	ret = ft_strchr(str, '=');
	printf("debut\n");
	printf("[ret = %s]\n", ret);
	printf("[after strchr str = %s]\n", str);
	return (0);
}