/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:44:41 by tidminta          #+#    #+#             */
/*   Updated: 2020/03/30 23:25:06 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <strings.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

/*
*************************************
**		TESTS FONCTIONS
*************************************
** int				ft_sumnum(int nb, ...);
*/

/*
*************************************
**		MACROS (VA_LIST & VA_ARGS)
*************************************
** typedef unsigned char *va_list;
** #define va_start(list, param) (list = (((va_list)&param) + sizeof(param)))
** #define va_arg(list, type)    (*(type *)((list += sizeof(type)) - sizeof(type)))
*/

/*
*************************************
**			STRUCTS_
*************************************
** /!\ check bits fields pour les flags (optimisation) /!\
** prevoir un autre .h pour les lignes +80
*/

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
}				t_infos_;

typedef struct	s_params_
{
	unsigned int		index;
	int					conv_len;
}				t_params_;

t_infos_		*ft_init_struct(void);

void			ft_display_struct(t_infos_ *struct_ptr);

void			ft_display_params(t_params_ *struct_ptr);

void			ft_fill_struct(t_infos_ *stct_p, va_list *lst_p, const char *s, unsigned int *i);

/*
*************************************
**		FONCTIONS D'AFFICHAGE
*************************************
*/

t_params_		*ft_init_params(void);

void			ft_printf_char(t_infos_ *st_, t_params_ *p);

void			ft_printf_pourcent(t_infos_ *st_, t_params_ *p);

void			ft_printf_string(t_infos_ *st_, t_params_ *p);

void			ft_printf_addr(t_infos_ *st_, t_params_ *p);

void			ft_printf_digits(t_infos_ *stct_, t_params_ *p);

void			ft_printf_unsigned(t_infos_ *st_, t_params_ *p);

void			ft_printf_hexa(t_infos_ *st_, t_params_ *p);

void			ft_print_loop(const char *str, t_params_ *p);

void 			ft_print_arg(t_infos_ *struct_, va_list *list, const char *s, t_params_ *p);

void			ft_putnbr_baselong(long long nbr, char *base, t_params_ *p);

void			ft_putnbr_base(unsigned long nbr, char *base, t_params_ *p);

void			ft_putstr_fd(char *s, int fd, t_params_ *p);

void			ft_putchar_fd(char c, int fd, t_params_ *p);

void			ft_putnbr_fd(int n, int fd, t_params_ *p);

int				ft_specific_print(char c);

/*
*************************************
**		FONCTIONS DE CONVERSION
*************************************
*/

int				ft_printf(const char *str, ...);

char			ft_convert_char(int char_);

/*
*************************************
**		FONCTION GET INFOS
*************************************
*/

char			ft_check_conv_spe(char car);

char			ft_check_flag(char car);

void			ft_get_flag(const char *s, unsigned int *index, t_infos_ *struct_ptr_);

int				ft_get_width(const char *s, unsigned int *index, va_list *lst_ptr);

int				ft_get_precis(const char *s, unsigned int *index, t_infos_ *struct_ptr_, va_list *lst_ptr);

void			ft_get_arg(va_list *list_ptr, t_infos_ *struct_ptr);

/*
*************************************
**		LIBFT FONCTIONS
*************************************
*/

void			*ft_memset(void *b, int c, size_t len);

size_t			ft_strlen(const char *s);

int				ft_atoi(const char *str);

void			ft_bzero(void *s, size_t n);

void			*ft_memcpy(void *dst, const void *src, size_t n);

void			*ft_memccpy(void *dst, const void *src, int c, size_t n);

void			*ft_memmove(void *dst, const void *src, size_t len);

int				ft_isalpha(int c);

int				ft_isdigit(int c);

int				ft_isalnum(int c);

int				ft_isascii(int c);

int				ft_isprint(int c);

int				ft_toupper(int c);

int				ft_tolower(int c);

char			*ft_strchr(const char *s, int c);

char			*ft_strrchr(const char *s, int c);

int				ft_strncmp(const char *s1, const char *s2, size_t n);

size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);

void			*ft_memchr(const void *s, int c, size_t n);

int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_memmove(void *dst, const void *src, size_t len);

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);

char			*ft_strnstr(const char *haystack, const char *needle, size_t len);

void			*ft_calloc(size_t count, size_t size);

char			*ft_strdup(const char *s1);

char			*ft_substr(char const *s, unsigned int start, size_t len);

char			*ft_strjoin(char const *s1, char const *s2);

void			ft_putchar(char c);

void			ft_putnbr(int nb);

char			*ft_strtrim(char const *s1, char const *set);

char			*ft_itoa(int n);

char			*ft_itoa2(unsigned int n);

char			*ft_itoa_base(unsigned int n);

char			**ft_split(char const *s, char c);

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

#endif
