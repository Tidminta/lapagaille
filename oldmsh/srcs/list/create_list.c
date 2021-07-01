/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 04:25:27 by loamar            #+#    #+#             */
/*   Updated: 2021/05/17 16:58:25 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static void			print_list(t_lair_list *lair_list)
{
	int		test;

	test = 1;
	t_list *current;

	current = lair_list->start;
	if (!lair_list || lair_list == NULL)
		printf("EMPTY LIST !... \n");
	printf("\n| PRINT LIST | \n");
	while (current->next)
	{
		printf("%d-> %s\n", test, current->content);
		current = current->next;
		test++;
	}
	printf("| FIN |\n");
	printf("size env_lair -> %d\n", lair_list->size);
	printf("first env_lair -> %s\n", lair_list->start->content);
	printf("end  env_lair -> %s\n", lair_list->end->content);
}

int 	ft_fill_empty_list(t_lair_list *lair_list, char *content)
{
	t_list	*new_element;

	if (!(new_element = (t_list *)malloc(sizeof(t_list))))
		return (-1);
	new_element->content = content;
	new_element->token = 0;
	new_element->previous = lair_list->start;
	new_element->next = lair_list->end;
	lair_list->end = new_element;
	lair_list->start = new_element;
	lair_list->size++;
	return (0);
}

int 	ft_fill_end_list(t_lair_list *lair_list, char *content)
{
	t_list	*new_element;

	if (!(new_element = (t_list *)malloc(sizeof(t_list))))
		return (-1);
	new_element->content = content;
	new_element->token = 0;
	new_element->next = NULL;
	new_element->previous = lair_list->end;
	lair_list->end->next = new_element;
	lair_list->end = new_element;
	lair_list->size++;
	return (0);
}

static	int 	is_empty_list(t_lair_list *lair_list)
{
	if (lair_list == NULL)
		return (1);
	return (-1);
}

t_lair_list		*clear_list(t_lair_list *lair_list)
{
	// print_list(lair_list);
	while (!is_empty_list(lair_list))
	{
		lair_list = pop_back_list(lair_list);
		// print_list(lair_list);
	}
	// printf("[AFTER CLEAR LIST]\n");
	// print_list(lair_list);
	return (NULL);
}

t_lair_list 		*pop_back_list(t_lair_list *lair_list)
{
	t_list 		*temp;
	t_list 		*tmp2;

	if (is_empty_list(lair_list))
		return (NULL);
	if (lair_list->start == lair_list->end)
	{
		free (lair_list);
		lair_list = NULL;
		return (NULL);
	}
	tmp2 = lair_list->end->previous;
	temp = lair_list->end;
	// lair_list->end->next = NULL;
	temp->next = NULL;
	temp->previous = NULL;
	free(temp->content);
	free(temp);
	temp = NULL;
	lair_list->size--;
	lair_list->end = tmp2;
	return (lair_list);
}

// FONCTIONS POUR CHECK CE QU IL Y A DANS LA LISTE CHAINEE
// static void 	print_list(t_lair_list *lair_list)
// {
// 	int 	test; // pour le printf
//
// 	test = 1; // pour le printf
// 	t_prompt_list *current;
//
// 	current = lair_list->start;
// 	printf("| DEBUT | \n");
// 	while (current != NULL)
// 	{
// 		printf("%d-> %s\n", test, current->content);
// 		current = current->next;
// 		test++; // pour le printf
// 	}
// 	printf("| FIN |\n");
// 	printf("size lair_list -> %d\n", lair_list->size);
// 	printf("first lair_list -> %s\n", lair_list->start->content);
// 	printf("end  lair_list -> %s\n", lair_list->end->content);
// }
//
// // fonction pour print a l enver
// static void 	print_inv_list(t_lair_list *lair_list)
// {
// 	t_prompt_list *current;
//
// 	current = lair_list->end;
// 	printf("[ ");
// 	while(current != NULL)
// 	{
// 		printf("%s : ", current->content);
// 		current = current->previous;
// 	}
// 	printf("]\n");
// }