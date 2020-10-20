/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 17:58:41 by tidminta          #+#    #+#             */
/*   Updated: 2020/10/20 19:04:28 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"

# define KEYPRESS 2
# define KEYRELEASE 3
# define WIN_WIDTH 800
# define WIN_HEIGHT 800
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define SPRITE 64
# define RESO_X_MAX 2560
# define RESO_Y_MAX 1440

/*
*************************************
**			  RAYCAST              **
*************************************
*/

typedef struct		s_player
{
	double	*zbuff;
	double	posx;
	double	posy;
	double	dirx;
	double	odirx;
	double	diry;
	double	planx;
	double	oplanx;
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
	double	movespeed;
	double	rot_s;
	double	texnum;
	double	wallx;
	double	step;
	double	texpos;
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
	int		m_up;
	int		m_down;
	int		m_right;
	int		m_left;
	int		m_left_key;
	int		m_right_key;
	int		texx;
	int		texy;
}					t_player;

/*
*************************************
**			  CUB3D                **
**			MAP INFOS			   **
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

typedef struct		s_res
{
	int	x;
	int	y;
}					t_res;

typedef struct		s_text
{
	char	*path;
	void	*img_p;
	int		*data;
	int		s_l;
	int		bpp;
	int		end;
}					t_text;

typedef struct		s_sprite
{
	double		x;
	double		y;
	double		dist;
	double		spx;
	double		spy;
	double		invdet;
	double		transx;
	double		transy;
	int			spscreenx;
	int			spheight;
	int			starty;
	int			startx;
	int			endy;
	int			endx;
	int			spwidth;
	int			stripe;
	int			texx;
	int			texy;
	int			d;
}					t_sprite;

typedef struct		s_infosprt
{
	t_sprite	**sp;
	int			*sporder;
	double		*spdist;
}					t_infosprt;

typedef struct		s_mapinfos
{
	char		**av;
	char		**map_tab;
	t_infosprt	*spinfos;
	t_list		*garbage;
	t_list		*map;
	t_text		**text;
	t_player	*p;
	t_mlx		*mlx;
	t_res		*res;
	int			*zbuff;
	int			floor_rgb;
	int			ceil_rgb;
	int			nbsp;
	int			fd;
	char		dir;
	size_t		line_max;
	size_t		col_max;
	size_t		win_w;
	size_t		win_h;
	size_t		start_x;
	size_t		start_y;
	
}					t_mapinfos;

/*
*************************************
**			  INIT                 **
*************************************
*/

int					ft_parse_open(char **av, t_mapinfos **map, t_list **list,
					t_list **garb);

t_mlx				*ft_start_mlx(t_mapinfos *map);

t_player			*ft_playerinit(t_mapinfos *map);

int					ft_init_text(t_mapinfos *map);

int					ft_free(t_mapinfos *map);

void				ft_get_dir(t_mapinfos *map);

void				ft_free_text(t_mapinfos *map);

void				*ft_garbage_collector(t_list **garbage, unsigned int size, int fd);


/*
*************************************
**			  FCTS                 **
*************************************
*/

int					ft_raycast(t_mapinfos *map_tmp,
					t_mlx *mlx_tmp, t_player *p);

int					ft_create_trgb(int t, int r, int g, int b);

int					ft_keypress(int key, t_mapinfos **map_tmp);

int					ft_keyrelease(int key, t_mapinfos **map_tmp);

int					ft_setmove(t_mapinfos *map_tmp);

void				ft_drawtext(t_mapinfos *map_tmp, t_mlx *mlx);

int					ft_get_index(t_player *p);

void				ft_lateral_move(t_mapinfos *map, int indice);

/*
*************************************
**			  PARSING              **
** 		CHECKER SI MAP FERMÉE 	   **
**		CHECK SI NSEW PRESENT      **
**		X FOIS DANS LA MAP		   **
*************************************
*/

t_list				*ft_map_gnl(int fd);

int					ft_get_res_x(t_list *infos, t_res *res);

size_t				ft_parseinfos(t_list **list, t_mapinfos **map,
					int fd, t_list *g);

t_mapinfos			*ft_init_mapinfos(int i, t_list *garbage);

int					ft_get_res_y(t_list *infos, t_res *res, int index);

int					ft_get_path(char *to_find, t_list *lst, char **s);

int					ft_get_rgb(char *to_find, t_list *lst, int *rgb);

size_t				ft_is_map_char(char c);

size_t				ft_is_map_line(char *s);

size_t				ft_check_rfc(t_mapinfos *map);

char				**ft_lst_to_tab(t_list *lst, t_mapinfos *map, size_t i);

void				ft_print_tab(char **tab);

size_t				ft_check_rfc(t_mapinfos *map);

int					ft_get_start_position(t_mapinfos *map, char **tab);

int					ft_map_is_closed(char **map);

void				ft_free_split(char **tab);

int					ft_error(t_list **garbage, char *s, int indice, int fd);

t_list				*ft_infos_gnl(int fd, t_list **mapinfos);

int					ft_check_path(t_list *lst, t_text **tex);

void				ft_freelst(t_list *l);

void				ft_clear_map(t_mapinfos *map);

/*
**************************************
**			SPRITE					**
**************************************
*/

void				ft_spritecast(t_mapinfos *map);
void				ft_sprites_projections(t_mapinfos *map);
int					ft_sprite_cpt(t_mapinfos *map);
void				ft_sprites(t_mapinfos *map);
void				ft_fill_sprites(t_mapinfos *map, int nb);
void				ft_spritesort(t_mapinfos *map);
int					ft_sprites_init(t_mapinfos *map);

/*
*************************************
**			  TOOLS                **
*************************************
*/

void				ft_print_tab(char **tab);
void				ft_print_list(t_list *map);
void				ft_print_mapinfos(t_mapinfos *map);
void				ft_print_playerinfos(t_player *player);
void				ft_print_spriteinfos(t_sprite *sp);

#endif
