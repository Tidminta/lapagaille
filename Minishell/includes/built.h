/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:47:40 by tidminta          #+#    #+#             */
/*   Updated: 2021/04/22 16:05:12 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_H
# define BUILT_H

typedef struct	s_ret
{
	char	*s;
	int		i;
}				t_ret;

int				ft_my_unset(t_msh *msh, t_list *lst);

int				ft_pop_node(t_env_lair *env_lair, char **unset_tab);

int				ft_my_export(t_msh *msh, t_list *element);

int				ft_my_env(t_env_lair *lst);

int				ft_my_pwd(void);

int				ft_my_cd(t_msh *msh, t_list *lst);

int				ft_my_echo(t_msh *msh, t_list *lst, int quot);

#endif
