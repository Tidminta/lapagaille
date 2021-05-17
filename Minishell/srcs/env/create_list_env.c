/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:26:48 by loamar            #+#    #+#             */
/*   Updated: 2021/05/17 16:03:26 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static void			print_list(t_env_lair *env_lair)
{
	int		test;

	test = 1;
	t_env_list *current;

	if (!env_lair || env_lair == NULL)
		printf("EMPTY LIST !... \n");
	printf("\n| PRINT LIST | \n");
	current = env_lair->start;
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

int				ft_fill_empty_env(t_env_lair *env_lair, char *content)
{
	t_env_list	*new_block;

	if (!(new_block = (t_env_list *)malloc(sizeof(t_env_list))))
		return (-1);
	new_block->content = content;
	new_block->previous = env_lair->start;
	new_block->next = env_lair->end;
	env_lair->end = new_block;
	env_lair->start = new_block;
	env_lair->size++;
	return (0);
}

int				ft_fill_end_env(t_env_lair *env_lair, char *content)
{
	t_env_list	*new_block;

	if (!(new_block = (t_env_list *)malloc(sizeof(t_env_list))))
		return (-1);
	new_block->content = content;
	new_block->next = NULL;
	new_block->previous = env_lair->end;
	env_lair->end->next = new_block;
	env_lair->end = new_block;
	env_lair->size++;
	return (0);
}

static int		is_empty_env(t_env_lair *env_lair)
{
	if (!env_lair || env_lair == NULL)
		return (SUCCESS);
	return (ERROR);
}

t_env_lair		*clear_env(t_env_lair *env_lair)
{
	t_env_list	*tmp;

	// print_list(env_lair);
	while (env_lair->size >= 0)
	{
		// printf("[clear env 82][envlair end content = %s\n]", env_lair->end->content);
		if (!ft_strncmp(env_lair->end->content, "(null)", 6) && env_lair->end->previous != NULL)
		{
			printf("content = NULL\n");
			tmp = env_lair->end->previous;
			env_lair->end = tmp;
		}
		// printf("[clear while][%s][%d]\n", env_lair->end->content, env_lair->size);
		env_lair = pop_back_env(env_lair);
		if (env_lair == NULL)
			return (env_lair);
		// printf("[env lair size][%d]\n", env_lair->size);
	}
	printf("CLEAR ENV DONE !\n");
	return (env_lair);
}

// if env lair is empty free env lair et return NULL
t_env_lair		*pop_back_env(t_env_lair *env_lair)
{
	t_env_list	*temp;
	t_env_list	*tmp2;

	// printf("101 [pop back env lair][%s][previous = %s]\n", env_lair->end->content, env_lair->end->previous->content);
	if (is_empty_env(env_lair) == SUCCESS || !env_lair)	
		return (NULL);
	// printf("[104 pop back env lair][%s]\n", env_lair->end->content);
	if (env_lair->start == env_lair->end)
	{
		// printf("[109][env lair start = end]\n");
		free(env_lair);
		// env_lair = NULL;
		printf("[114][env lair NULL]\n");
		return (NULL);
	}
	// printf("[111 pop back env lair][%s]\n", env_lair->end->content);
	temp = env_lair->end;
	tmp2 = env_lair->end->previous;
	// env_lair->end->next = NULL;
	// temp->next = NULL;
	// printf("[115 pop back env][%s]\n", temp->content);
	// free(temp->content);
	temp->content = NULL;
	// printf("[120][content remove done!]\n");
	temp->previous = NULL;
	temp->next = NULL;
	// temp->previous->next = NULL;
	free(temp);
	env_lair->end = tmp2;
	env_lair->end->next = NULL;
	// temp = NULL;
	env_lair->size--;
	// printf("[POP BACK ENV END OK !]\n");
	// print_list(env_lair);
	return (env_lair);
}


// pop bakc end a fixer, il met toujours le deuxieme maillon a NULL