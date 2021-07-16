/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 23:09:18 by tidminta          #+#    #+#             */
/*   Updated: 2021/07/08 20:08:13 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "./libshell.h"

void		handle_error(void);

void		ft_error(t_cut_cmd *cmd,char *str, int errornum);

#endif