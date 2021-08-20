/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 21:04:06 by tidminta          #+#    #+#             */
/*   Updated: 2021/08/18 21:04:07 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libshell.h"

int	print_env(t_msh *msh, t_cut_cmd *target)
{
	(void)msh;
	if (!target)
	{
		printf("[ENV IS VOID]\n");
		return (0);
	}
	while (target)
	{
		if (target->TOKEN != ENV_SOLO)
			printf("%s\n", target->elem);
		target = target->n;
	}
	return (1);
}
