/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:43:54 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/22 14:46:34 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "./libft.h"
# include "./get_next_line.h"
# include "./libftprintf.h"

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


// typedef struct	s_data
// {
// 	void	*img;
// 	int		*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// typedef struct s_img
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;
// 	t_data	img;
// }				t_img;
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


/*
*************************************
**			  TOOLS                **
*************************************
*/

void			ft_print_tab(char **tab);
void			ft_print_list(t_list *map);
void			ft_print_mapinfos(t_mapinfos *map);


#endif