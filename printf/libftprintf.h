/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:44:41 by tidminta          #+#    #+#             */
/*   Updated: 2020/02/29 22:24:08 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <strings.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

/* check bits fields pour les flags */

typedef struct	s_infos_
{
	char		conv_spe;
	int			flag_zero;
	int			flag_moins;
	int			width;
	int			precis;
	int			conv_len;
}				t_infos_;

int				ft_printf(const char *str, ...);

/*int				ft_sumnum(int nb, ...);*/

t_infos_		*ft_init_struct(void);

void			ft_get_flag(char *s, int *index, t_infos_ *struct_ptr_);

int				ft_get_width(char *s, int *index);

char			ft_check_conv_spe(char car);

int				ft_get_precis(char *s, int *index);

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

void			ft_putchar_fd(char c, int fd);

void			ft_putstr_fd(char *s, int fd);

void			ft_putendl_fd(char *s, int fd);

void			ft_putnbr_fd(int n, int fd);

char			*ft_strtrim(char const *s1, char const *set);

char			*ft_itoa(int n);

char			**ft_split(char const *s, char c);

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

#endif
