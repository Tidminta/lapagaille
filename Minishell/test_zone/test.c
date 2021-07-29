/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:41:30 by tidminta          #+#    #+#             */
/*   Updated: 2021/07/29 18:02:16 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libshell.h"

static void			print_env(t_msh *msh)
{
	int		test;

	test = 1;
	t_cut_cmd *env;

	env = msh->env->head;
	if (!env || env == NULL)
		printf("EMPTY LIST !... \n");
	printf("\n| PRINT LIST | \n");
	while (env)
	{
		printf("[%s]\n", env->elem);
		env = env->n;
	}
	printf("[head = %s][tail = %s]\n", msh->env->head->elem, msh->env->tail->elem);
	printf("| FIN [size = %d]|\n", msh->env->size);
}

static int				create_env_list(t_msh *msh, char *content)
{
	t_cut_cmd	*new_block;

	if (!msh->env->head || msh->env->head == NULL)
	{
		if (!(new_block = (t_cut_cmd *)malloc(sizeof(t_cut_cmd))))
			return (-1);
		new_block->elem = content;
		new_block->TOKEN = _UNASSIGNED;
		new_block->p = NULL;
		new_block->n = NULL;
		msh->env->head = new_block;
		msh->env->tail = new_block;
		msh->env->size = 1;
		return (SUCCESS);
	}
	return (ERROR);
}

static int				add_env(t_msh *msh, char *content)
{
	t_cut_cmd	*new_block;

	if (!(new_block = (t_cut_cmd *)malloc(sizeof(t_cut_cmd))))
		return (-1);
	new_block->elem = content;
	new_block->n = NULL;
	msh->env->tail->n = new_block;
	new_block->p = msh->env->tail;
	msh->env->tail = new_block;
	msh->env->size++;
	return (SUCCESS);
}

static int		is_empty_env(t_cut_cmd *env)
{
	if (!env || env == NULL)
		return (SUCCESS);
	return (ERROR);
}

void		init(t_msh **msh)
{
	*msh = (t_msh *)malloc(sizeof(t_msh));
	(*msh)->env = (t_env_list*)malloc(sizeof(t_env_list));
	(*msh)->env->head = NULL;
	(*msh)->env->tail = NULL;
	(*msh)->env->size = 0;
}

int	main(void)
{
	t_msh	*msh;

	init(&msh);
	if (is_empty_env(msh->env->head))
		create_env_list(msh, "block1");
	add_env(msh, "block2");
	add_env(msh, "block3");
	add_env(msh, "block4");
	print_env(msh);
	return (0);
}