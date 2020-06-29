/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 15:52:09 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/26 19:42:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <stdio.h>

/*
*************************************
**			  CUB3D                **
**			MAP INFOS			   **
*************************************
*/

typedef struct	s_res
{
	size_t	res_x;
	size_t	res_y;
}				t_res;

typedef struct	s_rgb
{
	size_t	red;
	size_t	green;
	size_t	bleue;
}				t_rgb;

typedef	struct		s_mapinfos
{
	t_res	*resolution;
	t_rgb	*floor;
	t_rgb	*ceil;
	t_list	*map;
	char	**map_tab;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*sprite;
}					t_mapinfos;

/*
*************************************
**			  CUB3D                **
**			 PARSING			   **
*************************************
**			A REVOIR			   **
**voidft_freemap(t_mapinfos **map);**
**  ?? 0 leaks sans ft_listclear   **
*************************************
*/

size_t			ft_parseinfos(t_list **list, t_mapinfos **map, int fd);

t_mapinfos		*ft_init_mapinfos(void);

t_list			*ft_infos_gnl(int fd, t_list **t_mapinfos);

t_list			*ft_map_gnl(int fd);

void			ft_get_res_x(t_list *infos, t_res *res);

void			ft_get_res_y(t_list *infos, t_res *res);

void			ft_get_path(char *to_find, t_list *lst, char **s);

void			ft_get_rgb(char *to_find, t_list *lst, t_rgb **rgb);

size_t			ft_is_map_char(char c);

size_t			ft_is_map_line(char *s);

char			**ft_lst_to_tab(t_list *lst);

void			ft_print_tab(char **tab);

/*
*************************************
**			  TOOLS                **
*************************************
*/

void			ft_print_list(t_list *map);
void			ft_print_mapinfos(t_mapinfos *map);

#endif
