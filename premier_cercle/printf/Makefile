# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 00:09:25 by tidminta          #+#    #+#              #
#    Updated: 2020/02/27 18:12:24 by tidminta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC  = gcc

RM	= rm -f

OBJ =	./lib/ft_memset.c\
		./lib/ft_bzero.c\
		./lib/ft_memcpy.c\
		./lib/ft_memccpy.c\
		./lib/ft_memchr.c\
		./lib/ft_memcmp.c\
		./lib/ft_memmove.c\
		./lib/ft_strlen.c\
		./lib/ft_isalpha.c\
		./lib/ft_isdigit.c\
		./lib/ft_isalnum.c\
		./lib/ft_strnstr.c\
		./lib/ft_strncmp.c\
		./lib/ft_strlcpy.c\
		./lib/ft_strlcat.c\
		./lib/ft_atoi.c\
		./lib/ft_strdup.c\
		./lib/ft_calloc.c\
		./lib/ft_substr.c\
		./lib/ft_strjoin.c\
		./lib/ft_strtrim.c\
		./lib/ft_split.c\
		./lib/ft_itoa.c\
		./lib/ft_putchar_fd.c\
		./lib/ft_putstr_fd.c\
		./lib/ft_putendl_fd.c\
		./lib/ft_putnbr_fd.c\
		./lib/ft_strchr.c\
		./lib/ft_strrchr.c\
		./lib/ft_isascii.c\
		./lib/ft_isprint.c\
		./lib/ft_strmapi.c\
		./lib/ft_toupper.c\
		./lib/ft_tolower.c\
		./lib/ft_printf.c


OBJ_OBJS	=	$(OBJ:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror 

LIB			= libftprintf.h

%.o : %.c
	$(CC) $(CFLAGS) -I. -o $@ -c $< 


$(NAME): $(OBJ_OBJS) $(LIB) Makefile
			ar rc $(NAME) $(OBJ_OBJS)
			ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ_OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	clean fclean all re
