/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidiane <tidiane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:32:41 by tidiane           #+#    #+#             */
/*   Updated: 2023/04/24 22:51:38 by tidiane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "includes.h"

char	*split_path(char **envp)
{
	int	i;
	char	*path;

	i = 0;
	while (ft_strncmp("PATH", envp[i], ft_strlen("PATH")))
	{
		i++;
	}
	path = ft_substr(envp[i], 5, (size_t)ft_strlen(envp[i]) - 3);
	printf("path = [%s]\n", path);
    ft_strtrim(path, "\n");
	printf("after trim = [%s]\n", path);
	return (path);
}

int main(int argc, char **argv, char **envp)
{
    char    *path;
    int     res;

    (void)argc;
    (void)argv;
    split_path(envp);
    return (0);
}