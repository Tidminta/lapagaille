/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:01:24 by tidminta          #+#    #+#             */
/*   Updated: 2019/11/18 20:02:46 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H

# include <string.h>
# include <stdlib.h>

void		*ft_memset(void *b, int c, size_t len);

size_t		ft_strlen(const char *s);

int			ft_atoi(const char *str);

void		ft_bzero(void *s, size_t n);

void		*ft_memcpy(void *dst, const void *src, size_t n);

void		*ft_memccpy(void *dst, const void *src, int c, size_t n);

void		*ft_memmove(void *dst, const void *src, size_t len);

int			ft_isalpha(int c);

int			ft_isdigit(int c);

int			ft_isalnum(int c);

int			ft_isascii(int c);

int			ft_isprint(int c);

int			ft_toupper(int c);

int			ft_tolower(int c);

char		*ft_strchr(const char *s, int c);

#endif
