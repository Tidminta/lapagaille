/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:01:40 by tidminta          #+#    #+#             */
/*   Updated: 2020/09/17 16:14:07 by tidminta         ###   ########.fr       */
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
# define KEYPRESSMASK 1L<<0
# define KEYRELEASE 3
# define KEYRELEASEMASK 1L<<1
# define WIN_WIDTH 800
# define WIN_HEIGHT 800
# define TEXWIDTH 64
# define TEXHEIGHT 64

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

typedef	struct		s_sprite
{
	double	x;
	double	y;
	double	dist;
}					t_sprite;

typedef	struct		t_infosprt
{
	t_sprite	**sp;
	int			*sporder;
	double		*spdist;
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
}					t_infosprt;

typedef	struct		s_mapinfos
{
	char		**map_tab;
	t_text		**text;
	t_mlx		*mlx;
	t_player	*p;
	t_res		*res;
	t_list		*map;
	t_infosprt	*spinfos;
	int			*zbuff;
	int			floor_rgb;
	int			ceil_rgb;
	int			nbsp;
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

int						ft_parse_open(char **av, t_mapinfos **map, t_list **list);

t_mlx					*ft_start_mlx(t_mapinfos *map, t_player *p);

t_player				*ft_playerinit(t_mapinfos *map);

void					ft_init_text(t_mapinfos *map);

int						ft_free(t_mapinfos *map);

void					ft_get_dir(t_mapinfos *map);


/*
*************************************
**			  FCTS                 **
*************************************
*/

int						ft_raycast(t_mapinfos *map_tmp, t_mlx *mlx_tmp, t_player *p);

int						ft_create_trgb(int t, int r, int g, int b);

int						ft_keypress(int key, t_mapinfos **map_tmp);

int						ft_keyrelease(int key, t_mapinfos **map_tmp);

int						ft_setmove(t_mapinfos *map_tmp);

void					ft_drawtext(t_mapinfos *map_tmp, t_mlx *mlx);


/*
*************************************
**			  PARSING              **
** 		CHECKER SI MAP FERMÉE 	   **
**		CHECK SI NSEW PRESENT      **
**		X FOIS DANS LA MAP		   **
*************************************
*/

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
**************************************
**			SPRITE					**
**************************************
*/

void				ft_spritecast(t_mapinfos *map);
// void				ft_bubblesort(int * tab);
void				ft_sprites_projections(t_mapinfos *map);
int					ft_sprite_cpt(t_mapinfos *map);

void				ft_fill_sprites(t_mapinfos *map);
void				ft_spritesort(t_mapinfos *map);

/*
*************************************
**			  TOOLS                **
*************************************
*/

void				ft_print_tab(char **tab);
void				ft_print_list(t_list *map);
void				ft_print_mapinfos(t_mapinfos *map);
void				ft_print_playerinfos(t_player *player);
void				ft_print_spriteinfos(t_infosprt *sp);

#endif