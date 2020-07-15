/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:01:40 by tidminta          #+#    #+#             */
/*   Updated: 2020/07/15 19:19:50 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <math.h>
# include <time.h>
# include "libft.h"
# include "libftprintf.h"
# include "mlx.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 800
// # define TILE_SIZE 30

/*
*************************************
**			  CUB3D                **
**			MLX INFOS			   **
*************************************
*/

typedef struct		s_img
{
	void	*img_p;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}					t_img;

typedef struct		s_mlx
{
	void	*mlx_p;
	void	*win;
	t_img	*img;
}					t_mlx;


/*
*************************************
**			  RAYCAST              **
*************************************
*/

typedef struct		s_player
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planx;
	double	plany;
	double	time;
	double	oldtime;
	double	camx;
	double	camy;
	double	raydx;
	double	raydy;
	double	sidedx;
	double	sidedy;
	double	deltadx;
	double	deltady;
	double	perpwd;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		x;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
}					t_player;

/*
*************************************
**			  CUB3D                **
**			MAP INFOS			   **
*************************************
*/
typedef struct		s_res
{
	size_t	x;
	size_t	y;
}					t_res;

typedef	struct		s_mapinfos
{
	t_res	*res;
	t_list	*map;
	size_t	line_max;
	size_t	col_max;
	size_t	win_w;
	size_t	win_h;
	size_t	start_x;
	size_t	start_y;
	t_mlx	*mlx;
	t_player	**p;
	int		floor_rgb;
	int		ceil_rgb;
	char	**map_tab;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*sprite;
}					t_mapinfos;
/*
*************************************
**			  FCTS                 **
*************************************
*/

int					ft_raycast(t_mapinfos **map_tmp, t_mlx **mlx_tmp, t_player *p);

t_mlx				*ft_start_mlx(t_mapinfos *map);

t_player			*ft_playerinit(void);

int					ft_create_trgb(int t, int r, int g, int b);

void				ft_clr(t_mapinfos *map, t_player *p);

int					ft_deal_key(int key, t_mapinfos *mlx);


/*
*************************************
**			  PARSING              **
** 		CHECKER SI MAP FERMÉE 	   **
**		CHECK SI NSEW PRESENT      **
**		FOIS DANS LA MAP		   **
*************************************
*/

int						ft_parse_open(char **av, t_mapinfos **map, t_list **list);

size_t                  ft_parseinfos(t_list **list, t_mapinfos **map, int fd);

t_mapinfos              *ft_init_mapinfos(void);

t_list                  *ft_infos_gnl(int fd, t_list **t_mapinfos);

t_list                  *ft_map_gnl(int fd);

int						ft_get_res_x(t_list *infos, t_res *res);

int						ft_get_res_y(t_list *infos, t_res *res, int index);

void                    ft_get_path(char *to_find, t_list *lst, char **s);

void                    ft_get_rgb(char *to_find, t_list *lst, int *rgb);

size_t                  ft_is_map_char(char c);

size_t                  ft_is_map_line(char *s);

size_t                  ft_check_rfc(t_mapinfos *map);

char                    **ft_lst_to_tab(t_list *lst, t_mapinfos *map);

void                    ft_print_tab(char **tab);

size_t					ft_check_rfc(t_mapinfos *map);

int						ft_get_start_position(t_mapinfos *map);

int						ft_map_is_closed(char **map);

void					ft_free_split(char **tab);

/*
*************************************
**			  TOOLS                **
*************************************
*/

void				ft_print_tab(char **tab);
void				ft_print_list(t_list *map);
void				ft_print_mapinfos(t_mapinfos *map);
void				map_render(int **data, char **map, t_mapinfos *infos);
void				ft_print_playerinfos(t_player *player);



#endif