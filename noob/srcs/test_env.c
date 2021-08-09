/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:15:25 by tidminta          #+#    #+#             */
/*   Updated: 2021/07/29 17:46:08 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libshell.h"

static void			print__env_list(t_msh *msh)
{
	int		test;

	test = 1;
	t_cut_cmd *env;

	if (!env || env == NULL)
		printf("EMPTY LIST !... \n");
	printf("\n| PRINT LIST | \n");
	env = msh->envp;
	while (env)
	{
		printf("[%s]\n", env->elem);
		env = env->n;
	}
	printf("| FIN |\n");
}

int				ft_fill_empty_env(t_msh *msh, t_cut_cmd *envp, char *content)
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
		return (SUCCESS);
	}
	return (ERROR);
}

int				ft_fill_end_env(t_msh *msh, t_env_list *env, char *content)
{
	t_cut_cmd	*new_block;

	if (!(new_block = (t_cut_cmd *)malloc(sizeof(t_cut_cmd))))
		return (ERROR);
	new_block->elem = content;
	new_block->n = NULL;
	msh->env->tail->n = new_block;
	new_block->p = msh->env->tail;
	msh->env->tail = new_block;
	return (SUCCESS);
}

static int		is_empty_env(t_cut_cmd *env)
{
	if (!env || env == NULL)
		return (SUCCESS);
	return (ERROR);
}
