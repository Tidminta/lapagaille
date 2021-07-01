/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:56:22 by loamar            #+#    #+#             */
/*   Updated: 2021/05/17 17:16:35 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static void			print_list(t_env_lair *env_lair)
{
	int		test;

	test = 1;
	t_env_list *current;

	current = env_lair->start;
	if (!env_lair || env_lair == NULL)
		printf("EMPTY LIST !... \n");
	printf("\n| PRINT LIST | \n");
	while (current != NULL)
	{
		printf("%d-> %s\n", test, current->content);
		current = current->next;
		test++;
	}
	printf("| FIN |\n");
	printf("size env_lair -> %d\n", env_lair->size);
	printf("first env_lair -> %s\n", env_lair->start->content);
	printf("end  env_lair -> %s\n", env_lair->end->content);
}

static void		free_split(char **str)
{
	int		index;

	index = 0;
	while (str[index])
	{
		free(str[index]);
		str[index] = NULL;
		index++;
	}
	free(str[index]);
	free(str);
	str = NULL;
}

int			free_data(t_msh *msh)
{
	if (msh->data)
	{
		if (msh->data->prompt_data)
			free_split(msh->data->prompt_data);
		free(msh->data);
		return (1);
	}
	return (0);
}

int			free_lair_list(t_msh *msh)
{
	if (msh->lair_list)
	{
		msh->lair_list = clear_list(msh->lair_list);
		free(msh->lair_list);
		return (1);
	}
	return (0);
}

int			free_env_lair(t_msh *msh)
{
	if (msh->env_lair)
	{
		msh->env_lair = clear_env(msh->env_lair);
		free(msh->env_lair);
		// printf("AFTER ENV CLEANING\n");
		// print_list(msh->env_lair);
		return (1);
	}
	return (0);
}
