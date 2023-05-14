/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tminta <tminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:18:00 by tminta            #+#    #+#             */
/*   Updated: 2023/05/13 21:14:36 by tminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

char	*first_word(char *str)
{
	char				*result;
	size_t				i;

	i = 0;
	while (str[i] && str[i] != ' ')
	{
		i++;
	}
	result = ft_substr(str, 0, i);
	return (result);
}

void	ft_clean(t_pipe *box)
{
	free(box->pipe);
	
}