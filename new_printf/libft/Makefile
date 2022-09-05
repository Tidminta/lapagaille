# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 00:09:25 by tidminta          #+#    #+#              #
#    Updated: 2020/01/16 21:12:59 by tidminta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC  = gcc

RM	= rm -f

OBJ =	./ft_memset.c\
		./ft_bzero.c\
		./ft_memcpy.c\
		./ft_memccpy.c\
		./ft_memchr.c\
		./ft_memcmp.c\
		./ft_memmove.c\
		./ft_strlen.c\
		./ft_isalpha.c\
		./ft_isdigit.c\
		./ft_isalnum.c\
		./ft_strnstr.c\
		./ft_strncmp.c\
		./ft_strlcpy.c\
		./ft_strlcat.c\
		./ft_atoi.c\
		./ft_strdup.c\
		./ft_calloc.c\
		./ft_substr.c\
		./ft_strjoin.c\
		./ft_strtrim.c\
		./ft_split.c\
		./ft_itoa.c\
		./ft_putchar_fd.c\
		./ft_putstr_fd.c\
		./ft_putendl_fd.c\
		./ft_putnbr_fd.c\
		./ft_strchr.c\
		./ft_strrchr.c\
		./ft_isascii.c\
		./ft_isprint.c\
		./ft_strmapi.c\
		./ft_toupper.c\
		./ft_tolower.c

OBJ_OBJS	=	$(OBJ:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror 

LIB			= libft.h

%.o : %.c
	$(CC) $(CFLAGS) -I. -o $@ -c $< 


$(NAME): $(OBJ_OBJS) $(LIB) Makefile
		 	@ar rc $(NAME) $(OBJ_OBJS)
			ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ_OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	clean fclean all re
