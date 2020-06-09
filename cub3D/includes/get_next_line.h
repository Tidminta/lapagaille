/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:15:28 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/09 12:11:54 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

int				get_next_line(int fd, char **line);

char			*ft_strchr2(char *s, int c);

char			*ft_strjoin2(char *s1, char *s2);

char			*ft_strdup2(char *s1);

int				ft_strlen2(char *str);

void			ft_putstr(char *str);

char			*ft_substr2(char *s, int start, int len);

void			ft_putstr(char *str);

void			ft_bzero2(void *s, size_t n);

char			*ft_where_is_nl(char *s);

void			ft_check_params(int fd, char **line, char **buff, char **str);

int				ft_check(int fd, char **line, char **str, void *buff);

#endif
