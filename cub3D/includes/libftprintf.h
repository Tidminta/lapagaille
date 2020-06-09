/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:44:41 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/09 17:55:27 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdlib.h>
# include <strings.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_infos_
{
	char				conv_spe;
	char				*arg_str;
	int					flag_zero;
	int					flag_moins;
	int					flag_diez;
	int					width;
	int					precis;
	int					is_precis;
	int					conv_len;
	int					arg_char;
	int					arg_int;
	unsigned int		arg_uint;
	unsigned int		arg_hexa;
	unsigned long		arg_addr;
	unsigned long		arg_bin;
}				t_infos_;

typedef struct	s_params_
{
	unsigned int		index;
	int					conv_len;
}				t_params_;

t_infos_		*ft_init_struct(void);

t_params_		*ft_init_params(void);

void			ft_display_struct(t_infos_ *struct_ptr);

void			ft_display_params(t_params_ *struct_ptr);

void			ft_fill(t_infos_ *stct_p, va_list *lst_p,
							const char *s, t_params_ *p);

/*
*************************************
**		FONCTIONS D'AFFICHAGE
**	ft_printf(const char *s, ...) __attribute__((format(printf, 1, 2)));
*************************************
*/

int				ft_printf(const char *s, ...);

void			ft_printf_char(t_infos_ *st_, t_params_ *p);

void			ft_printf_pourcent(t_infos_ *st_, t_params_ *p);

void			ft_printf_string(t_infos_ *st_, t_params_ *p);

void			ft_printf_addr(t_infos_ *st_, t_params_ *p);

void			ft_printf_digits(t_infos_ *stct_, t_params_ *p);

void			ft_printf_unsigned(t_infos_ *st_, t_params_ *p);

void			ft_printf_hexa(t_infos_ *st_, t_params_ *p);

void			ft_printf_bin(t_infos_ *st_, t_params_ *p);

void			ft_print_loop(const char *str, t_params_ *p);

void			ft_print_arg(t_infos_ *struct_, va_list *list,
								const char *s, t_params_ *p);

void			ft_putnbr_baselong(long long nbr, char *base, t_params_ *p);

void			ft_putnbr_base(unsigned long nbr, char *base, t_params_ *p);

void			ft_putstr_fd2(char *s, int fd, t_params_ *p);

void			ft_putchar_fd2(char c, int fd, t_params_ *p);

void			ft_putnbr_fd2(int n, int fd, t_params_ *p);

int				ft_specific_print(char c);

/*
*************************************
**		DECOUPE DE FONCTIONS
*************************************
*/

void			ft_string_flagm(t_infos_ *st_, t_params_ *p, size_t len);

void			ft_string_0flag(t_infos_ *st_, t_params_ *p, size_t len);

void			ft_bin_flagm(t_infos_ *st_, t_params_ *p, size_t len);

void			ft_bin_flag0(t_infos_ *st_, t_params_ *p, size_t len);

void			ft_bin_0flag(t_infos_ *st_, t_params_ *p, size_t len);

void			ft_unsigned_flagm(t_infos_ *st_, t_params_ *p, size_t len);

void			ft_unsigned_flag0(t_infos_ *st_, t_params_ *p, size_t len);

void			ft_unsigned_0flag(t_infos_ *st_, t_params_ *p, size_t len);

void			ft_addr_0flag(t_infos_ *st_, t_params_ *p, size_t len);

void			ft_addr_flagminus(t_infos_ *st_, t_params_ *p, size_t len);

void			ft_d_0flag(t_infos_ *st_, t_params_ *p, size_t len);

void			ft_d_flag0(t_infos_ *st_, t_params_ *p, size_t len);

void			ft_d_flagminus(t_infos_ *st_, t_params_ *p, size_t len);

void			ft_hexa_0_flags(t_infos_ *st_, t_params_ *p, size_t len);

void			ft_hexa_flag_0(t_infos_ *st_, t_params_ *p, size_t len);

void			ft_hexa_flagminus(t_infos_ *st_, t_params_ *p, size_t len);

void			ft_hexa_0_flags_b(t_infos_ *st_, t_params_ *p, size_t len);

void			ft_hexa_flag_0_b(t_infos_ *st_, t_params_ *p, size_t len);

void			ft_hexa_flagmoins_b(t_infos_ *st_, t_params_ *p, size_t len);

/*
*************************************
**		FONCTIONS DE CONVERSION
*************************************
*/

int				ft_printf(const char *str, ...);

/*
*************************************
**		FONCTION GET INFOS
*************************************
*/

char			ft_check_conv_spe(char car);

char			ft_check_flag(char car);

void			ft_get_flag(const char *s, t_params_ *p_, t_infos_ *st_);

int				ft_get_width(const char *s, t_params_ *p, va_list *lst_ptr);

int				ft_get_p(const char *s, t_params_ *p, t_infos_ *struct_ptr_,
														va_list *lst_ptr);

void			ft_get_arg(va_list *list_ptr, t_infos_ *struct_ptr);

/*
*************************************
**		LIBFT FONCTIONS
*************************************
*/

void			ft_bzero(void *s, size_t n);

void			*ft_calloc(size_t count, size_t size);

int				ft_atoi(const char *str);

int				ft_isdigit(int c);

int				ft_isprint(int c);

char			*ft_strdup(const char *s1);

char			*ft_substr2(char const *s, size_t start, size_t len);

size_t			ft_strlen(const char *s);

/* ************************************ */
/*				LISTES					*/
/* ************************************ */

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void *content);

void			ft_lstadd_back(t_list **alst, t_list *new);

void			ft_lstadd_front(t_list **alst, t_list *new);

int				ft_lstsize(t_list *lst);

t_list			*ft_lstlast(t_list *lst);

void			ft_lstdelone(t_list *lst, void (*del)(void*));

void			ft_lstclear(t_list **lst, void (*del)(void *));

void			ft_lstiter(t_list *lst, void (*f)(void *));

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
	void (*del)(void *));

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
	void (*del)(void *));

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

size_t			ft_parsemap(t_list **list, t_mapinfos **map, int fd);

t_list			*ft_map_gnl(int fd);

void			ft_get_res_x(t_list *infos, t_res *res);

size_t			ft_get_res_y(t_list *infos, t_res *res);

size_t			ft_get_path(char *to_find, t_list *lst, char **s);

size_t			ft_get_rgb(char *to_find, t_list *lst, t_rgb *rgb);

// 


//ft_get_path
//ft_get_rgb

/*
*************************************
**			  TOOLS                **
*************************************
*/

void			ft_print_list(t_list *map);
void			ft_print_mapinfos(t_mapinfos *map);

#endif
